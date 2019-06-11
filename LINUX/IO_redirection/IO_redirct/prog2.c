#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
int fd;
char str[20];

fd = open("datafile",O_CREAT | O_WRONLY | O_APPEND,0660);//terminal no

if(fd == -1)
{
perror("open");
exit(0);
}
//close(1); it is imortant line
printf("fd = %d in %d \n",fd,getpid() );
close(1); // close stdout
// see result without duplicating the fd and close the stdout.
int newfd = fcntl(fd,F_DUPFD,0);
printf("newfd = %d in %d \n",newfd,getpid() );

close(fd);
close(newfd);

exit(0);
}
