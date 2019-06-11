#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main( int argc,char *argv[] )
{
DIR *dp;
struct dirent *ptr;

dp = opendir(argv[1]);
ptr = readdir(dp);

printf("%ld %s \n",ptr->d_ino,ptr->d_name);
ptr++;
printf("%ld %s \n",ptr->d_ino,ptr->d_name);
closedir(dp);
}
