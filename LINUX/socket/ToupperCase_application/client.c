#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>


int main(int argc,char *argv[]){

int sockfd;
char buffer[256];
int portno = atoi(argv[1]);//port address

struct sockaddr_in server_addr;
struct hostent* server;

server = gethostbyname(argv[2]);//IP address

bzero((char *)&server_addr,sizeof server_addr);

server_addr.sin_port = htons(portno);
server_addr.sin_family = AF_INET;
	
sockfd = socket(AF_INET,SOCK_STREAM,0);

if(sockfd == -1){
perror("error in soket\n");
exit(0);
}

bcopy((char *)server->h_addr,(char *)&server_addr.sin_addr.s_addr,server->h_length);

if(connect(sockfd,(struct sockaddr *)&server_addr,sizeof server_addr)==-1){
perror("Error in connect\n");
exit(0);
}
int n;
while(1){
n=0;
printf("Enter data:\t");
__fpurge(stdin);
scanf("%[^\n]s",buffer);

n = write(sockfd,buffer,strlen(buffer));

if(n<0){
perror("Error in writing\n");
exit(0);
}
n=0;
bzero(buffer,256);
n = read(sockfd,buffer,256);
if(n<0){
perror("Error in reading\n");
exit(0);
}
printf("server --> client: %s\n",buffer);
bzero(buffer,256);
}
close(sockfd);
return 0;
}
