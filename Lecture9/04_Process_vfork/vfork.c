#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
	int variable1 = 2;
	pid_t forkResult = vfork();
	if(forkResult == 0)
	{
	printf("PID %d: -Nooooooooooo\n", getpid());
	printf("Child process PID: %d\n", getpid());
	printf("Group process PID: %d\n", getpgrp());
	printf("Group leader PID: %d\n", getpgid(getpid()));
	printf("variable1 address = %p\n", &variable1);
	variable1 = 7;
	_exit(EXIT_SUCCESS);
	}
	else if(forkResult < 0)
	{
		printf("error :%d while trying to fork()\n", forkResult);
	}
	else
	{
		int status;
		//(void)waitpid(forkResult,&status,0); 
		printf("PID %d: ", getpid());
		printf("-New process, I'm you father !\n");
		printf("variable1 address = %p", &variable1);
		variable1 = 14;
	}
	printf("Variable 1: %d\n", variable1);
}
