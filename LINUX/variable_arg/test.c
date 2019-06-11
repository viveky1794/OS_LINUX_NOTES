#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
//void print(int add,char *ptr, ... )
int print(int add,char *ptr, ... )
{
va_list handler;
puts(ptr);
va_start(handler,ptr);
while(ptr=va_arg(handler,char *))
	puts(ptr);
va_end(handler);
return ++add;
}

int main()
{

printf("%p\n",print);
//printf("%d\n",print(1,"int","char","Float","double",NULL));

}
