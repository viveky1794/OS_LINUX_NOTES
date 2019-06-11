#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
/* without wait() sys_call */

printf("Before fork =%d\n",getpid());

if(fork()== 0)
	sleep(5);
wait(NULL);

printf("After Fork=%d\n",getpid());

/* with wait() sys_call  */
/*
printf("Before fork =%d\n",getpid());

if(fork()== 0)
	sleep(5);
wait(NULL);

printf("After Fork=%d\n",getpid());

*/

}
