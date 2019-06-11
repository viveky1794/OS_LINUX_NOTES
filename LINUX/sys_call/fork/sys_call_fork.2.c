#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{

if( fork()==0 )
{
printf("First if %d\n",getpid() );
exit(0);
}

else if( fork()==0 )
{
printf("2nd if %d\n",getpid() );
exit(0);
}
printf("parent=%d\n",getpid());
exit(0);
}
