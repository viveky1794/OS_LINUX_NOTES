#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	if( fork() )
	{puts("Parent");
	printf("C-%d P-%d\n",getpid(),getppid());
	sleep(7);
	printf("Parent--exiting\n");
	exit(0);
	}
	else if( fork() )
	{puts("Child");
	printf("C-%d P-%d\n",getpid(),getppid() );
	sleep(5);
	printf("Child --exiting\n");
	exit(0);
	}

}
