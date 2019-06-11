#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	if( fork()==0 )
	{
	printf("C-%d P-%d\n",getpid(),getppid());
	sleep(2);
	printf("Child--existing\n");
	exit(0);
	}
exit(0);
}
