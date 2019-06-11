/* execute multiple command.
 * take them from command line argument and execute sequentially
 * do this by exec() funaction.
 */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
printf("Parent process id:%d\n",getppid());
printf("current process id:%d\n",getpid());

argv[argc]='\0';
//execvp(argv[1],argv+1);
for(int i=1;i<argc;i++)
execvp(argv[1],argv+1);

return 0;
}
