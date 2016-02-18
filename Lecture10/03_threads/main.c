#include <stdio.h>
#include <math.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

sem_t sem;

typedef struct
{
	unsigned long value;
	int isPrime;
}numberStruct;

int isPrime(unsigned long number)
{
	int a;
	printf("%d\n", number);
	for(a = 2; a * a < number; a++)
	{
		if(number % a == 0) return 0;
	}
	return 1;
}


void * checkForAPrime(void * context)
{
	//static sem_t sem;
	sem_wait(&sem);
	numberStruct * numberToCheck = context;
	numberToCheck->isPrime = isPrime(numberToCheck->value);
	sleep(2); // used for indicating that the semaphore is working
	sem_post(&sem);
	pthread_exit(NULL);
}

int main()
{
	char numberString[2048];
	char currentNumber[12];
	memset(numberString, 0, sizeof(numberString));
	memset(currentNumber, 0 , sizeof(currentNumber));
	numberStruct numbers[200];
	scanf("%s", numberString);
	int i = 0;
	int index = 0;
	int currentNumberIndex = 0;
	int length = strlen(numberString);
	for(i = 0; i < length; i++)
	{
		if(numberString[i] != ',')
		{
			currentNumber[index++] = numberString[i];
		}
		else
		{
			numbers[currentNumberIndex++].value = atol(currentNumber);
			memset(currentNumber,0,index);
			index = 0;
		} 
	}
	numbers[currentNumberIndex++].value = atol(currentNumber);
	//static sem_t sem;
	sem_init(&sem, 0, 4);
	pthread_t * threads = malloc(sizeof(pthread_t) * currentNumberIndex);
	int numberOfNumbers = currentNumberIndex;
	for(i = 0; i < currentNumberIndex; i++)
	{
		//sem_wait(&sem);
		pthread_create(&threads[i], NULL, checkForAPrime, &numbers[i]);
	}
	for(i = 0; i < currentNumberIndex-1; i++)
	{
		pthread_join(threads[i], 0);
		printf("%d,", numbers[i].isPrime);
	}
	printf("%d\n", numbers[i].isPrime);
	return 0;
}
