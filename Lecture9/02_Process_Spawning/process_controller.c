#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Spawning hello_1\n");
	printf("Hello_1 finished with status : %d\n", system("./hello_1"));
	printf("Spawning hello_2\n");
	printf("Hello_2 finished with status : %d\n", system("./hello_2"));
	return 0;
}

