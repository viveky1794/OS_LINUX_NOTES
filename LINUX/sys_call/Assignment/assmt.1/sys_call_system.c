#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
char cmd[100];
printf("Parent process id:%d\n",getppid());
printf("Current Pocess id:%d\n",getpid());

for(int i=1;i<argc;i++)
{
if(i==1)
{
strcpy(cmd,argv[i]);
}
else
{
strcat(cmd," ");
strcat(cmd,argv[i]);
}
}

system(cmd);
return 0;

}
