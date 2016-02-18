#include <stdio.h>
#include <string.h> // for memset

int main()
{
	char dataString[1023];
	memset(dataString, 0, sizeof(dataString));
	int i = 0;
	while(1)
	{
		char c = getchar();
		if(c == '.' || i > sizeof(dataString)/sizeof(dataString[0])) break;
		else 
		{
			dataString[i]=c;
			if(i % 2 == 0) dataString[i]++;
			else dataString[i]--;
			i++;
		}
	}

	printf("%s\n", dataString);
	return 0;
}

