#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,const char *argv[])
{
char ch;
int fd1,fd2;
fd1 = open(argv[1],O_RDONLY);

if(fd1 == -1)
{	perror("open");
exit(1);
}

fd2 = creat(argv[2],0660);

if(fd2 == -1)
{	perror("open");
exit(1);
}

printf("fd1 = %d,fd2=%d\n",fd1,fd2);
while( read(fd1,&ch,1)==1 )
write(fd2,&ch,1);

close(fd1);
close(fd2);
}
