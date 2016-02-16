#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>


int main()
{
	pid_t  forkResult; // create forkResult var for forking
	static pthread_mutex_t * lock; // create pointer to the mutex lock
	lock = mmap(NULL, sizeof * lock, PROT_READ | PROT_WRITE,  MAP_SHARED |
 MAP_ANONYMOUS, -1, 0); // in order to share same value between processes we must mmap it. 
	pthread_mutexattr_t attr; // we create attribute for the mutex init
	pthread_mutexattr_init (&attr);
	pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED); // set the attribute with PROCESS_SHARED mask
	
	int i = 0;
	if(pthread_mutex_init(lock, &attr) != 0) // initialize the lock
	{
		printf("cannot initialize lock\n");
		return -2;
	}

	for(i = 0; i<200;i++)
	{
		forkResult=fork(); // moment of forking
		if(forkResult==0)
		{
			printf("A new fork with ID %d is spawned\n", getpid());
			break;
			// do something if you want to
		}
		else if(forkResult<0)
		{
			printf("Error number : %d\n", forkResult);
			return -1;
		}
		else
		{
			// parent action
		}
	}
	if(forkResult > 0)
	{
		while(wait())
		{
			//printf("In da while\n");
			if(errno == ECHILD) break;
		}
		printf("Finished \n");
		pthread_mutex_destroy(lock); // destroy the lock
		return 0;
	}
	else if(forkResult == 0)
	{
		/* we have race condition, where multiple processes are trying to lock for a single lock (spin lock))*/
		pthread_mutex_lock(lock); // lock the mutex

		/* critical section */
		usleep(200000); 
		printf("Process with PID: %d has exited\n", getpid());
		/*end of critical section*/

		pthread_mutex_unlock(lock); // unlock the mutex 
		exit(0); // send system call to the parrent that the child has exited with success
	}
}
