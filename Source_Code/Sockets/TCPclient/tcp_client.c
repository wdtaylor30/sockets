#if 0
William Daniel Taylor
February 17, 2018
TCP Client
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main() {

	//creates a client socket
	int netSocket;
	netSocket = socket(AF_INET, SOCK_STREAM, 0);

	//specifies an address for the socket
	struct sockaddr_in server_address;

	//specifies address family
	server_address.sin_family = AF_INET;

	//specifies port
	server_address.sin_port = htons(9002);

	//specifies address
	server_address.sin_addr.s_addr = INADDR_ANY;

	//attempts to make connection
	int connectionStatus = connect(netSocket, (struct sockaddr *) &server_address, sizeof(server_address));
	//returns an int to tell if connection is made (0) or not (1)


	//error handling
	if (connectionStatus == -1) {
		printf("There was an error making a connection to the remote socket.\n\n");
	}//end if

	
	//recieves data from server
	char serverResponse[256];
	recv(netSocket, &serverResponse, sizeof(serverResponse), 0);


	//prints data that is recieved
	printf("The server sent: %s", serverResponse);

	//closes socket
	close(netSocket);

	return 0;
}
