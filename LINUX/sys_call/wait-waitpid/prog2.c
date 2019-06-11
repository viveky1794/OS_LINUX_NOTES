#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
/* with wait() sys_call  */

printf("Before fork =%d\n",getpid());

if(fork()== 0)
	sleep(5);

printf("After Fork=%d\n",getpid());

wait(NULL);
//parent is waiting for child proccess exit status.
//After 5 second child will return the status 

}
