#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

int PF(char *ch,...);

int main()
{
PF("%d\n",PF("vivek"));
}


int PF(char *ch,...)
{
int i=0,cnt=0;
char output;
va_list list;
va_start(list,ch);

do{
   output = ch[i];

if(output == '%')
{	
char *string,a[32];
int j=0,digit;
double temp,f;
switch(ch[++i])
{
	case 's':
		string = va_arg(list,char * ); while(putchar(string[j++]))cnt++; j=0; break;

	case 'd':
	      // for integers only long and long long integers are still pending do them.	
		digit = va_arg(list,int); 
		
		while(digit)
		{	
		a[j++] =(digit%10)+48;
		digit/=10;
		}
		a[j] = '\0';
		for(j=j-1;j>=0;j--)
		{ putchar(a[j]); cnt++; }
		j=0;
		break;
		
	case 'c':
		putchar(va_arg(list,int)); cnt++; break;//char will pramoted to int while passing.
	
	case 'f':
		f = va_arg(list,double );//float is pramoted to double while passing.
		temp  = f;
		digit = (int)f;
		while(digit)
		{
			a[j++] = digit%10 + 48;
			digit/=10;
		}
		a[j]='\0';
		for(j;j>=0;j--)
		{ putchar(a[j]); cnt++; }
		
		putchar('.'); cnt++;

		f = f - (int)temp;
		digit = (int)(f*1000000);
		j=0;
		while(digit)
		{
		a[j++] = digit%10 + 48;
		digit/=10;
		}
		a[j]='\0';
		for(j;j>=0;j--)
		{ putchar(a[j]); cnt++; }

		break;

		/*
	case 'p':
	       //for address printing
		string = va_arg(list,char *);//still pending see lab code	
		
		while(string[j])
		{
			a[j]= string[j];
		       	j++;
		}
*/
}

}
else
{  putchar(output); cnt++; }

}while(ch[i++] != '\0');

va_end(list);
return cnt-1;//return no of charcter printed on STDOUT.
}





