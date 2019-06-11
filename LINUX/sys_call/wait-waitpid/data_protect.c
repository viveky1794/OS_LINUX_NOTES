#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int g=1;
int main()
{
g++;
printf("%d in %d\n",getpid(),g);
if( fork() )
{
sleep(2);
g+=10;
printf("%d: %d\n",getpid(),g);
sleep(4);
printf("parent exiting\n");
exit(0);
}
else
{
g+=100;
printf("%d: %d\n",getpid(),g);
sleep(3);
printf("child exiting\n");
exit(0);
}
}
