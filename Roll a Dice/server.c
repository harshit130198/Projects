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

void servicePlayers(int, int);

int main(int argc, char *argv[])  {
	int server_socket, port_number, pid, player1, player2;
	struct sockaddr_in server_address;

	if(argc !=2) {
		printf("Call Model :: <Port> \n");
		exit(0);
	}
	
	//create a socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket==0) {
		perror("\n Socket Failed. \n");
		exit(1);
	}

	// Assigning IP and Port 
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr=htonl(INADDR_ANY);
	sscanf(argv[1], "%d", &port_number);
	server_address.sin_port = htons((uint16_t)port_number);

	// Binding the server socket with structure 
	if(bind(server_socket,(struct sockaddr *) &server_address, sizeof(server_address))<0) {
		perror("Bind Failed \n");
		exit(1);
	}
	if(listen(server_socket, 3)<0) {
		perror("Listen Failed \n");
		exit(1);
	}

	printf("Bind Successful\n\n");
	printf("Waiting for Players\n");

	while(1) {
		//waiting for Player 1
		player1=accept(server_socket,(struct sockaddr *)NULL,NULL);
    		printf("Player Connected\n");

		//waiting for Player 2
		player2=accept(server_socket,(struct sockaddr *)NULL,NULL);
		printf("Player Connected\n");

		printf("\nTwo players connected, Let the game begin\n");

		//Creating Child Process
		pid = fork();
		if(pid == 0) {
			servicePlayers(player1, player2);
		}
		close(player1);
		close(player2);
	}

	return 0;
}

void servicePlayers(int player1, int player2) {
	int final_score[2]={0}, recv_score, maxScore=100;
	char client_m[255], c1[255], c2[255];

	//Reading Player1 Name
	if(!read(player1, c1, 100)){
    		close(player1);
    		fprintf(stderr,"Client data not received\n");
		exit(0);  
	}

	//Reading Player2 Name
	if(!read(player2, c2, 100)){
    		close(player2);
    		fprintf(stderr,"Client data not received\n");
		exit(0);
	}

	while(1) {

		printf("\n\n");

		//Message for Player 1 to start playing game
		strcpy(client_m,"You can now play");
		write(player1, client_m, strlen(client_m)+1);

		//Reading Player1 Score
		if(!read(player1, client_m, 255)){
    			close(player1);
    			fprintf(stderr,"Client data not received\n");
			exit(0);
		}

		//Type conversion of score
		sscanf(client_m,"%d",&recv_score);

		final_score[0] += recv_score;
		printf("%s's Total Score :: %d\n",c1,final_score[0]);
		sleep(2);

		//Message for Player 2 to start playing game
		strcpy(client_m, "You can now play");
		write(player2, client_m, strlen(client_m)+1);

		//Reading Player1 Score
		if(!read(player2, client_m, 255)){
    			close(player2);
    			fprintf(stderr,"Client data not received\n");
			exit(0);
		}

		//Type conversion of score
		sscanf(client_m,"%d",&recv_score);
		final_score[1] += recv_score;
		printf("%s's Total Score :: %d\n",c2,final_score[1]);
		sleep(2);

		if (final_score[0] >= maxScore){
			strcpy(client_m, "Game over: you won the game");
			write(player1, client_m, strlen(client_m)+1);

			strcpy(client_m, "Game over: you lost the game");
			write(player2, client_m, strlen(client_m)+1);

			close(player1);
			close(player2);

			printf("\n%s won the game!\n",c1);
			printf("\nWaiting for 2 new players to Connect!\n");
			exit(0);
		
		}

		if (final_score[1] >= maxScore){
			strcpy(client_m, "Game over: you won the game");
			write(player2, client_m, strlen(client_m)+1);

			strcpy(client_m, "Game over: you lost the game");
			write(player1, client_m, strlen(client_m)+1);

			close(player1);
			close(player2);

			printf("\n%s won the game!\n",c2);
			printf("\nWaiting for 2 new players to Connect!\n");
			exit(0);
		
		}
	
	}
}


