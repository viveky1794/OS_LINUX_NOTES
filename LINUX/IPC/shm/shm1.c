/*
 * this is not working .
 *
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main()
{
int id;
char *ptr;
id = shmget(1,3,IPC_CREAT|06660);
printf("id=%d\n",id);
ptr = shmat(id,NULL,0);

while(1)
{
printf("%d :%c :%c :%c \n",getpid(),ptr[0],ptr[1],ptr[2]);
sleep(1);
system("clear");
}

}

