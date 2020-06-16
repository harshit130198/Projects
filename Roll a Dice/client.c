/*
COMP 8567

Advanced System Programming 
Team Members :
				HARSHIT PATEL (105179597) 
				MAHIMA PATEL  (105179890)
 */

#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	
	int network_socket, port_number, score;
	char server_m[255], s_score[255] ;
	struct sockaddr_in server_address;

	if(argc !=4) {
		printf("Call Model :: <Player Name> <Port> <IP> \n");
		exit(0);
	}

	//create a socket
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(network_socket==0) {
		perror("\n Socket Failed. \n");
		exit(1);
	}

	//Assigning IP and Port
	server_address.sin_family = AF_INET;
	sscanf(argv[2], "%d", &port_number);
	server_address.sin_port = htons((uint16_t)port_number);

	//converting IPV4 address from presentation to network format
	if(inet_pton(AF_INET,argv[3],&server_address.sin_addr) < 0){
		fprintf(stderr, " inet_pton() has failed\n");
		exit(2);
	}


	//Connecting with server
	if(connect(network_socket,(struct sockaddr *) &server_address, sizeof(server_address))<0) {
		perror("Connection Failed \n");
		exit(1);
	}

	printf("%s has connected to the server \n",argv[1]);
	write(network_socket,argv[1],strlen(argv[1])+1);

	while(1) {

		//reading message from server
		if(read(network_socket, server_m, 255) < 0) {
   			fprintf(stderr, "read() error\n");
			exit(0);
		}

		//Player can roll the dice
		if((strcmp(server_m,"You can now play") == 0))	{
			printf("%s",server_m);

			//generation of random numbers
			score = (int)time(NULL) % 7 + 1;

			//Converting score from int to char array and send it to server
			sprintf(s_score, "%d", score);
			printf("\n%s's  Obtained Score : %s\n\n",argv[1],s_score);
			strcpy(server_m,s_score);
			write(network_socket, server_m, strlen(server_m)+1);
		}

		//player wins the game
		if((strcmp(server_m,"Game over: you won the game") == 0)){
			printf("I won the game\n\n");
			close(network_socket);
			exit(0);
		}

		//player lost the game
		if((strcmp(server_m,"Game over: you lost the game") == 0)){
			printf("I lost the game\n\n");
			close(network_socket);
			exit(0);
		}
	}
	
	return 0;
}