#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int ret;
	ret = fork();
	if(ret == -1)
	{
	perror(" fork ");
	exit(0);
	}
	else if(ret == 0)
	{
	printf("Child -->%d\n",getpid());
	}
	else
	{
	printf("Parent-->%d\n",getpid());
	}
exit(0);
}
