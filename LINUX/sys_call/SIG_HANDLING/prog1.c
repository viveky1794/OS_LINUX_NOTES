#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main()
{
printf("%d\n",getpid());
//while(1);//if you give any signal to this process then it will do work according to that. I give SIG(8) which is floating point Error.
	//this program will be aborted by the Kernal.If we do not want this then we have to handle this Signal.
	//signal(8,SIG_IGN)--> Ignore the signal no. 8
	//after writing this statement we are changing the default status of signal table in PCB and enforcing it to Ignore the Signal.
	//These signals are MACROS of ISR's addresses. So kernel know that after receiving these signals. which task it has to do.
signal(8,SIG_IGN);
while(1); // now if you give this signal to your process now kernel know what it should do with this signal.
}
