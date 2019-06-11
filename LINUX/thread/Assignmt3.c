#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int cnt;
pthread_mutex_t m;

void* fun1(void *p)
{
pthread_mutex_lock(&m);
cnt  = cnt -5;
printf("in func 1-->%d\n",cnt);
pthread_mutex_unlock(&m);
pthread_exit(NULL);
}

void* fun2(void *q)
{

pthread_mutex_lock(&m);
cnt = cnt+10;
printf("in func 2-->%d\n",cnt);
pthread_mutex_unlock(&m);
pthread_exit(NULL);
}

int main()
{
pthread_t tpid1,tpid2;
/*
 * I am getting unpredictable output.
 * Acccording to me i should get first threads output.
 * but it is randomly working.it is not waiting for termination of thread 1;
 *
 */

while((cnt++) < 100)
{
pthread_create(&tpid1,NULL,fun1,NULL);
pthread_join(tpid1,NULL);
pthread_create(&tpid2,NULL,fun2,NULL);
pthread_join(tpid2,NULL);

}

exit(0);
}
