#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char **argv)
{

printf("Parant process:%d\n",getppid());
printf("process:%d\n",getpid());

argv[argc]='\0';

execvp(argv[1],argv+1);//second argument "must be"  NULL terminated. 

return 0;
}
