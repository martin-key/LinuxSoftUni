#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char firstName[32];
	char lastName[32];
	memset(firstName, 0, sizeof(firstName));
	memset(lastName, 0, sizeof(lastName));

	scanf("%s %s", firstName, lastName);
	printf("%s, %s\n", lastName, firstName);
	return 0;
}


