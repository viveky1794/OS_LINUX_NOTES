#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
printf("Before Forking %d\n",getpid());

fork();//fork-1

printf("After Forking-1 %d\n",getpid());

fork();// fork-2

printf("After Forking-2 %d\n",getpid());


exit(0);
}
