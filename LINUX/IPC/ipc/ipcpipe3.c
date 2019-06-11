#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char str[] = ".........................";
int main()
{
int p1[2],p2[2];
int ret1,ret2;
ret1 = pipe(p1);
ret2 = pipe(p2);
if( fork() == 0)
{
/* chid is sending data to parent through the interprocessing mechanism.
 * here we are using only one pipe is working in half deplux mode.
 * now we will use two pipes for full duplex.
 */
puts("\nIn child");
printf("str:%s\n",str);
sleep(5);
close(p1[0]);	/* we are closing reading end */

strcpy(str,"/* vector form child */");
write(p1[1],str,strlen(str)+2);
sleep(5);

close(p2[1]);	/*we have closed second  pipe's Writng End */
read(p2[0],str,40);
printf("child is  reading->str:%s\n",str);
puts("child has exit.");
exit(0);
}


else
{
sleep(3);
puts("\nIn parent");
/* we are closing first pipe's Writing End */
close(p1[1]);

read(p1[0],str,40);
printf("str:%s\n",str);
sleep(3);

/* we are closing second pipe's Reading End */
close(p2[0]);

printf("parent is writing-->");
strcpy(str,"parent has write");
write(p2[1],str,strlen(str)+2);
sleep(5);

}

return 0;
}
