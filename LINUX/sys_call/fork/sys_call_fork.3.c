#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
int ret;
ret = fork();
switch(ret)
{
	case -1: printf("-1\n"); break;
	case 0: printf("0\n"); break;
	default: printf("default"); break;
}
printf("After switch.....\n");
exit(0);
}
