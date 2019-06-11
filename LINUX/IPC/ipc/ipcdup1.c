#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int fd[2],nbytes;
pid_t childpid;

pipe(fd);

if((childpid = fork())== -1)
{
perror("fork");
exit(0);
}

if(childpid == 0)/* child process */
{
close(0);//close stdin
int newfd = dup(fd[0]);//duplecate reading end

write(fd[0],"Hello",10);

//execlp("ps -el","ps -el",NULL);
exit(0);
}
else/* parent process */
{
/*
close(fd[1]);//close writing
nbytes = read(fd[0],readbuffer,sizeof(readbuffer));
printf("received string:%s\n",readbuffer);
*/
}
return 0;
}

