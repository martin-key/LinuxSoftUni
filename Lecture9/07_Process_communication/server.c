#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>


#define FIFO_FILE "/tmp/MYFIFO"
int main()
{
	FILE *fp;
	char readbuff[50];
	// create a FIFO buffer if it doesn't exist
	umask(0);
	mknod(FIFO_FILE, S_IFIFO|0666, 0);

	while(1)
	{
		fp=fopen(FIFO_FILE, "r");
		memset(readbuff, 0, sizeof(readbuff)/sizeof(readbuff[0]));
		fgets(readbuff, sizeof(readbuff)/sizeof(readbuff[0]), fp);
		printf("PID %d: Received string : %s\n",getpid() , readbuff);
		fclose(fp);
	}
	return 0;
}

