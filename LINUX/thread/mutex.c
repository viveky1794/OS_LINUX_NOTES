/*
 * use gcc mutex.c -lpthread
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t m;
pthread_t tid1,tid2;
int g=1;

void *f1(void *p)
{
printf("in thread 1....\n");

pthread_mutex_lock(&m);

printf("in thread 1..g=%d\n",g);
sleep(4);
g+=10;
printf("thread 1:g(+10)=%d\n",g);

pthread_mutex_unlock(&m);

printf("thread 1--> exiting\n");
pthread_exit(NULL);
}

void *f2(void *q)
{
printf("in thread 2\n");
pthread_mutex_lock(&m);
sleep(2);
g+=100;
printf("thread 2:g(+100)=%d\n",g);
pthread_mutex_unlock(&m);
printf("thread 2-->exiting\n");
pthread_exit(NULL);
}

int main()
{
pthread_mutex_init(&m,NULL);
pthread_create(&tid1,NULL,f1,NULL);
pthread_create(&tid2,NULL,f2,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);

}
