#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int fd[2],nbytes;
pid_t childpid;
char string[] = "Hello,world\n";
char readbuffer[80];

pipe(fd);

if((childpid = fork())== -1)
{
perror("fork");
exit(0);
}

if(childpid == 0)/* child process */
{
close(fd[0]);//close reading end
write(fd[1],string,strlen(string)+1);
exit(0);
}
else/* parent process */
{

close(fd[1]);//close writing
nbytes = read(fd[0],readbuffer,sizeof(readbuffer));
printf("received string:%s\n",readbuffer);

}
return 0;
}

