#include<signal.h>
#include<stdio.h>
#include<unistd.h>
void ISR(int n)
{
printf("In ISR signal no--> %d\n",n);
return;
}
int main()
{
signal(SIGINT,ISR);// when signal will come go to user Define ISR and return back; 
printf("%d\n",getpid());
sleep(10);

signal(SIGINT,SIG_IGN);// SIG_IGN--> ignore the signal
printf("%d\n",getpid());
sleep(10);

signal(SIGINT,SIG_DFL);//SIG_DFL -->update PCB signal table with signal's default nature.
while(1);
}
