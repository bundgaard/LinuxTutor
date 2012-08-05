#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
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
int main(void)
{
	pid_t pid;
	pid = fork();
	if(pid > 0) // Parent
	{
		int i;
		for(i = 0; i < 10; i++)
		{

			printf("parent: %d\n",i);
			wait(NULL);
		}
	}else if(pid == 0) // child process
	{
		fib(50);
	}
	else
	{
		exit(-1);
	}
	
	return 0;
}