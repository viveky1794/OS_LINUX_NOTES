/*
 * date:
 */ 


#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>

void error(char* msg){
	perror(msg);
	exit(0);
	}


int main(int argc,char *argv[]){

	if(argc < 2){
		fprintf(stderr,"Error: Port no is not given\n"); 
		exit(1);
	}

	int sockfd, newsockfd, portno, n; // intergers for return types of API
	char buffer[255]; // buffer for I/O operation
	struct sockaddr_in serv_addr, cli_addr; // structures about to know its members open $ man 7 IP
	socklen_t clilen; // opque data type for length;
	
	/* tcp_socket $ man tcp
	*
	* STEP:1
	*/
	sockfd = socket(AF_INET, SOCK_STREAM,0); // using socket() API we are initilizing TCP/IP protocol for more information open man pages of Socket.

	if(sockfd == -1){
		error("Error opening Socket\n");
	}

	bzero((char *)&serv_addr, sizeof(serv_addr));// it is for erasing data from stucture or we can use memset() funcation also.

	portno = atoi(argv[1]);// command line argument, converting string to integers.
	
	/* open $ man 7 IP */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno); // network byte orders so convert port no form host to network.
	
	/*
	 * STEP:2
	 */
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
		error("Bindinf Error\n");
	}

	/* 
	 * STEP:3
	 */
	listen(sockfd,5); // listen max 5 clients 
	clilen = sizeof(cli_addr);

	/*
	 * STEP:4
	 */
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr,&clilen);

	if(newsockfd < 0){
		error("Error on accept\n");
	}

	while(1){
	bzero(buffer,256);//clear buffer
	n = read(newsockfd,buffer,255);//reading and stroing into buffer
	
	if( n < 0 ){
	       	error("Error while readind");
       	}

	printf("Client: %s\n",buffer); // printing buffer

	bzero(buffer,256); // clear buffer
	fgets(buffer,255,stdin);

	n = write( newsockfd, buffer, strlen(buffer) );
	if(n < 0)
		error("Error while writing\n");

	int i = strncmp("Bye",buffer,3);
	if(i==0) 
		break;

	}
	
	close(newsockfd);
	close(sockfd);
	return 0;

}
