#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER 100000

int main()
{
	time_t t = clock();
	int numberOfPrimes = 0;
	
	for(int i = MAX_NUMBER-1; i > 1; i--)
	{	
		int flag = 0;
		for(int j = 2; j <= sqrt(i);j++)
		{
			if(i % j == 0)
			{	flag = 1;
				break;
			}
		}
		if(flag == 0) numberOfPrimes++;

	}
	printf("%d\n", numberOfPrimes);
	printf("%lf\n",(double)((double)clock() - t)/CLOCKS_PER_SEC);
	return 0;
}
