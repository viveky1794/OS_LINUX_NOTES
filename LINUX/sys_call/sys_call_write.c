#include<stdio.h>
#include<string.h>
int main()
{
char str[]="MESSAGE FROM WRITE";
printf("message from printf\n");
write(1,str,strlen(str));
puts(" ");
return 0;
}
