#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t m;
//pthread_t tpid[3];
pthread_t tpid1,tpid2,tpid3;
int cnt;

void *upper(void *p)
{

pthread_mutex_lock(&m);

printf("%c ",65+(cnt));
pthread_mutex_unlock(&m);

pthread_exit(NULL);
}

void *lower(void *p)
{

pthread_mutex_lock(&m);

printf("%c ",97+(cnt));

pthread_mutex_unlock(&m);

pthread_exit(NULL);
}

void *integer(void *p)
{

pthread_mutex_lock(&m);

printf("%d ",(cnt+1));

pthread_mutex_unlock(&m);

pthread_exit(NULL);
}

int main()
{
pthread_mutex_init(&m,NULL);

for(int i=0; i < 26; i++ )
{
pthread_create(&tpid1,NULL,integer,NULL);
pthread_join(tpid1,NULL);

pthread_create(&tpid2,NULL,upper,NULL);
pthread_join(tpid2,NULL);

pthread_create(&tpid3,NULL,lower,NULL);
pthread_join(tpid3,NULL);

cnt++;
puts(" ");
}

exit(0);
}
