/*
 * this program is same as Assigment1 with different logic and method.
 * both program is giving me same output. but it can be better.
 *
 * here mutex lock is not playing any roll. thread are calling as a funcation only.
 * which we dont want at all.it should be 
 * 
 * Now it is working fine as i want it is beautifull example of dead lock also. 
 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t u,l,i;
pthread_t tpid1,tpid2,tpid3;

int cnt;

void *upper(void *p)
{
pthread_mutex_lock(&u);

printf("%c ",65+(cnt));
cnt++;
pthread_exit(NULL);
}

void *lower(void *p)
{

pthread_mutex_lock(&l);

printf("%c ",97+(cnt));

pthread_mutex_unlock(&u);

pthread_exit(NULL);
}

void *integer(void *p)
{

pthread_mutex_lock(&i);

printf("%d ",(1+(cnt)));
pthread_mutex_unlock(&l);

pthread_exit(NULL);
}

int main()
{
pthread_mutex_init(&u,NULL);
pthread_mutex_init(&l,NULL);
pthread_mutex_init(&i,NULL);

pthread_mutex_lock(&u);
pthread_mutex_lock(&l);

for(int ii=0; ii < 26; ii++ )
{
	pthread_create(&tpid1,NULL,upper,NULL);
	pthread_create(&tpid2,NULL,lower,NULL);
	pthread_create(&tpid3,NULL,integer,NULL);

	pthread_join(tpid1,NULL);
	pthread_mutex_unlock(&i);
	puts(" ");
}

exit(0);
}
