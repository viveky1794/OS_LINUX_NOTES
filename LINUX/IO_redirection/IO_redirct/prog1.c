#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
int fd;
char str[20];

fd = open("/dev/pts/3",O_WRONLY | O_APPEND);//terminal no

if(fd == -1)
{
perror("open");
exit(0);
}

while(1)
{
puts("Enter a string");
fgets(str,20,stdin);
write( fd,str,strlen(str) );//output redirected to terminal 3
}

exit(0);
}
