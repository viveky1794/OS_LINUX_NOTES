/* execute multiple command.
 * take them from command line argument and execute sequentially
 * do this by system() funaction.
 */
#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
printf("Parent process id:%d\n",getppid());
printf("current process id:%d\n",getpid());

for(int i=1;i<argc;i++)
	system(argv[i]);

return 0;
}
