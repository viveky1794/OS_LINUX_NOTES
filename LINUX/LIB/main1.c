/* this code is to  demostrate you that how library works */

#include<stdio.h>

int main()
{
int x,y,result,choice;
printf("Enter 2 int:");
scanf("%d %d",&x,&y);

printf("1:SUM 2:MUL\n");
scanf("%d",&choice);

if(choice==1)
result=sum(x,y);

if(choice==2)
result=mul(x,y);

printf("result=%d\n",result);
return 0;
}
