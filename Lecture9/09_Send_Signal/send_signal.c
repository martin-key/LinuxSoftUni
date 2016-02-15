#include <stdio.h>
#include <signal.h>

void main()
{
	int i = 0;
	for(i=0; i< 5; i++)
	{
		printf("%d\n", i);
		sleep(1);
	}
	raise(SIGINT);
	while(1);
}
