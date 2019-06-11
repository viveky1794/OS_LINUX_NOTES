#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
time_t t;
time(&t);
printf("%u\n",(unsigned int)t);	//time in seconds since 01-01-1970
exit(0);
}
