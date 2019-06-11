#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_t tpid1,tpid2;

void *f1(void *p)
{
printf("in thread1...\n");
while(1);
}

void *f2(void *q)
{
printf("in thread2...\n");
while(1);
}

int main()
{
pthread_create(&tpid1,NULL,f1,NULL);
pthread_create(&tpid2,NULL,f2,NULL);
printf("2 thread created\n");
//sleep(10);
//pthread_exit(0);//it will wait till thread will not exit/change state.

pthread_join(tpid1,NULL);//simliar to waitpid()
pthread_join(tpid2,NULL);
exit(0);
}
