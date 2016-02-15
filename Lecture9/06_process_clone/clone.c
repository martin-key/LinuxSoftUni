#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// 64kB stack
#define STACK 1024*64

// The child thread will execute this function
int threadFunction( void* argument ) {
     printf( "child thread entering\n" );
     close((int*)argument);
     printf( "child thread exiting\n" );
     return 0;
}

int main() {
     void* stack;
     pid_t pid;
     int fd;
     fd = open("/dev/null", O_RDWR); 
     if (fd < 0) {
         perror("/dev/null");
         exit(1);
     }

     // Allocate the stack
     stack = malloc(STACK);
     if (stack == 0) {
         perror("malloc: could not allocate stack");
         exit(1);
     }
     printf("Creating child thread\n");

     // Call the clone system call to create the child thread
     pid = clone(&threadFunction,
                 (char*) stack + STACK,
                 SIGCHLD | CLONE_FS | CLONE_FILES |
                  CLONE_SIGHAND | CLONE_VM,
                 (void*)fd);

     if (pid == -1) {
          perror("clone");
          exit(2);
     }

     // Wait for the child thread to exit
     pid = waitpid(pid, 0, 0);
     if (pid == -1) {
         perror("waitpid");
         exit(3);
     }

     // Attempt to write to file should fail, since our thread has
     // closed the file.
     if (write(fd, "c", 1) < 0) {
         printf("Parent:\t child closed our file descriptor\n");
     }

     // Free the stack
     free(stack);

     return 0;
}
