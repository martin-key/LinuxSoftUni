#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
	int variable1 = 2;
	pid_t forkResult = fork();
	if(forkResult == 0)
	{
	printf("PID %d: -Nooooooooooo\n", getpid());
	printf("Child process PID: %d\n", getpid());
	printf("Group process PID: %d\n", getpgrp());
	printf("Group leader PID: %d\n", getpgid(getpid()));
	variable1++;
	}
	else if(forkResult < 0)
	{
		printf("error :%d while trying to fork()\n", forkResult);
	}
	else 
	{
		printf("PID %d: ", getpid());
		printf("-New process, I'm you father !\n");
		variable1--;
	}
	//printf("Variable 1: %d\n", variable1);
}
