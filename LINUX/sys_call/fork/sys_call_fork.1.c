#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
printf("Fork-1 %d\n",getpid());

fork();//fork-2

printf("Fork-2 %d\n",getpid());

fork();// fork-3

printf("Fork-3 %d\n",getpid());

fork();// fork-4

printf("Fork-4 %d\n",getpid());

exit(0);
}
