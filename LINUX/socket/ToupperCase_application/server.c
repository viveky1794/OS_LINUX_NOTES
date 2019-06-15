#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdarg.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<ctype.h>


int main(int argc,char *argv[]){
int sockfd;
int portno = atoi(argv[1]);
char buffer[256];
struct sockaddr_in server_addr,client_addr;

sockfd = socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1){
perror("Error in Socket\n");
exit(0);
}

bzero((char *)&server_addr,sizeof server_addr);

server_addr.sin_family = AF_INET;
server_addr.sin_port  = htons(portno);
server_addr.sin_addr.s_addr = INADDR_ANY;

if( bind(sockfd,(struct sockaddr *) &server_addr,sizeof server_addr) == -1){
perror("Binding error\n");
exit(0);
}

listen(sockfd,5);
socklen_t clilen = sizeof client_addr;
int newsockfd = accept(sockfd,(struct sockaddr *) &client_addr,&clilen);

if(newsockfd == -1){
perror("accept error\n");
exit(0);
}

while(1){

	
	int n = read(newsockfd,buffer,255);
	
	if(n<0){
	perror("error in reading\n");
	exit(0);
	}
	int i;
	for(i=0;i<strlen(buffer);i++){
	if(isalpha(buffer[i]))
	buffer[i] = toupper(buffer[i]);	
	}
	buffer[i]='\0';
	n=0;
	n = write(newsockfd,buffer,strlen(buffer));
	
	if(n<0){
		perror("Error in writing\n");
		exit(0);
	}
	bzero(buffer,256);
}

return 0;
}
