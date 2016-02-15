#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main()
{
	printf("Hello from the program exec with PID: %d\n", getpid());
	execl( "exec2","", NULL);
}
