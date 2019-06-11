#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int i;
	for(i=0;i<=5;i++)
	{
	if ( fork()==0 )
	printf("child = %d.....\n",getpid());
	exit(0);
	}
exit(0);
}
