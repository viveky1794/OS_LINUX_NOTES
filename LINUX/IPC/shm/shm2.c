/*
 * This is not compelet yet.it is also not working.
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
ptr[rand()%3] = rand()%26 + 65;
sleep(1);
}

}

