/*
 * this is not working properly.
 *see this code in other's notebooks.

 */

#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<signal.h>

void f1(int );

int main()
{
struct sigaction newAct;
struct rlimit v = {5,10};

//signal(SIGXCPU,f1);
signal(24,f1);

newAct.sa_handler = f1;
newAct.sa_flags = 0;	//NO flag has choosen

sigemptyset(&newAct.sa_mask);

sigaction(24,&newAct,NULL);

setrlimit(RLIMIT_CPU,&v);

printf("%d\n",getpid() );

}

void f1(int n)
{
int i,j;
printf("in f1 due to signal %d\n",n);
for(i=1;i<999999;i++)
	for(j=1;j<9999;j++);

puts("ISr complete");
}
