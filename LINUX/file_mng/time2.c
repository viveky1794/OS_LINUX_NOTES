#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
time_t t;
struct tm *tmptr;
char datestring[20],timestring[20];

time(&t);

tmptr = localtime(&t);
strftime(datestring,20,"%F",tmptr);//set the format of time
strftime(timestring,20,"%T",tmptr); // set time format
printf("%s %s \n",datestring,timestring);
exit(0);
}
