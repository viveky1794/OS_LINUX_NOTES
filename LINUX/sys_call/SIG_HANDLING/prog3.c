#include"header.h"

void ISR(int n)
{
	printf("In ISR due to signal no. %d\n",n);
wait(NULL);
}

int main()
{

if( fork() )
{
signal(SIGCHLD,ISR); // if we comment out this line then ISR will not work and child will become zombie
printf("In parent-->%d\n",getpid());
while(1);// parent will be in infinite loop. 
}
else
{
int t;
srand(getpid());
t = rand()%5 + 1;
printf("In child-->%d\n",getpid());
printf("Child delay for %d seconds \n",t);
sleep(t);
printf("Child %d  exit\n",getpid());
exit(0);
}

}
