#include <unistd.h>
#include <stdio.h>
#include <signal.h>


void handler(int sig)
{
	printf("Executing handler\n");
	signal(sig, SIG_DFL);
}

int main()
{
	signal(SIGINT, handler);
	while(1)
	{
		printf("Hello world\n");
		sleep(1);
	}
	return 0;
}
