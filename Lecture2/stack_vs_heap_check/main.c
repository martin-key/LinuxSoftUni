#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <inttypes.h>

int is_stack(void * ptr)
{
	pthread_t self = pthread_self();
	pthread_attr_t attr;
	void *stack;
	size_t stacksize;
	pthread_getattr_np(self, &attr);
	pthread_attr_getstack(&attr, &stack, &stacksize);
	return ((uintptr_t) ptr >= (uintptr_t) stack && (uintptr_t) ptr < (uintptr_t) stack +
	stacksize);
}

int main()
{
	int x;
	int * p1 = (int *) malloc (sizeof(int));
	int * p2 = &x;
	char str[3] = "asd";
	printf("p1: %d\np2: %d\nstr[3]: %d\n", is_stack(p1), is_stack(p2),is_stack(str));
	return 0;
}
