#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 1
long fib(long c);
void *PrintFibonacci(void *arguments)
{
	long threadId;
	threadId = (long)arguments;
	fib(40);
	pthread_exit(NULL);
}
long fib(long c)
{
	long f0 = 0;
	long f1 = 1;
	long idx;
	for(idx = 0; idx < c; idx++){
		long tmp;
		if(idx <= 1)
			tmp = idx;
		else
		{
			tmp = f0 + f1;
			f0 = f1;
			f1 = tmp;
		}
		printf("%ld\n",tmp);
		
		
	}
	return 0L;
}

int main(int argc, char **argv){
	int n, first = 0, second = 1, next, c;
	pthread_t thread;
	
	for(c = 0; c < 10; c++)
	{
		if(c <= 1)
			next = c;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
		printf("%d ",next);
	}
	printf("\n");
	pthread_create(&thread, NULL,PrintFibonacci,(void*)1);
	pthread_exit(NULL);
	return 0;
}