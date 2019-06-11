#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
struct stat v;

if( stat(argv[1],&v)==-1 ){
printf("error\n");  exit(0); 
}

printf("%d\nsize=%u\ninode=%u\nf1(link)=%lu\n",v.st_mode,(unsigned int)v.st_size,v.st_ino,v.st_nlink);
}
