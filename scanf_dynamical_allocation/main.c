#include <stdio.h>
#include <stdlib.h>

int main()
{
	char * str;
	//int asd ;
	//scanf("%d", &asd);
	//printf("%d", asd);
	scanf("%ms", &str);
	printf("\n%s\n", str);
	free(str);
	return 0;
}
