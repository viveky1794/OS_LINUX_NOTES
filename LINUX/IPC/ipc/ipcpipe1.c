#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char str[] = "............";
int main()
{
int p[2];

if( pipe(p)==-1 )
{
perror("pipe");
exit(0);
}

printf("p[0->]%d\tp[1]->%d\n",p[0],p[1]);

if( ( fork() ) ==0 )
{
printf("str1:%s\n",str);
sleep(5);
printf("str:%s\n",str);
exit(0);
}

else
{
sleep(3);
strcpy(str,"vector");
printf("parent:str:%s\n",str);
sleep(4);
exit(0);
}

return 0;
}
