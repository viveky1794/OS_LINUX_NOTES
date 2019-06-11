#include"header.h"

void func()
{
char arr[1000000];
static int cnt;
cnt++;
printf("in func...%d\n",cnt);
if(cnt<20)
	func();

return ;
}
int main()
{
struct rlimit v;

if( getrlimit( RLIMIT_STACK,&v )==-1 )
	perror("getlimit");
else
	printf( "%u %u\n",(unsigned int)v.rlim_cur,(unsigned int)v.rlim_max );

v.rlim_cur*=3;//these two lines are changing the stack limit for this process.
		
setrlimit(RLIMIT_STACK,&v);

	printf( "After setting the limits\n%u %u\n",(unsigned int)v.rlim_cur,(unsigned int)v.rlim_max );
func();
}

