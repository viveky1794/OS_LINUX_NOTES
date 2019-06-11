#include"header.h"

void func()
{
char arr[8000000];
static int cnt;
cnt++;
printf("in func...%d\n",cnt);
if(cnt<20)
	func();

return ;
}
int main()
{
func();
}

