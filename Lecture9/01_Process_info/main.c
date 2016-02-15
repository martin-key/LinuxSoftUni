#include <stdio.h>
#include <unistd.h>


int main()
{
	printf("PID of the process is : %d\n", getpid());
	printf("Group PID of the process is : %d\n", getpgrp());
	printf("Group leader PID is : %d\n", getpgid(getpid()));
	return 0;
}

