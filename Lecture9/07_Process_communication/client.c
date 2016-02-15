#include <stdio.h>
#include <stdlib.h>

#define FIFO_FILE "/tmp/MYFIFO"
int main(int argc, char ** argv)
{
	FILE * fp;

	if((fp = fopen(FIFO_FILE, "w")) != NULL)
	{
		fputs(argv[1], fp);
		fclose(fp);
	}
	else return -1;
}

