#if 0
William Daniel Taylor
February 17, 2017
TCP Server
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {

	//string to send to client
	char serverMessage[256] = "You have reached the server!";

	//creates the server socket
	int serverSocket;
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	//define the server address
	struct sockaddr_in server_address;

	//specifies address family
	server_address.sin_family = AF.INET;

	//specifies port
	server_address.sin_port = htons(9002);

	//specifies address
	server+address.sin_addr.s_addr = INADDR_ANY;

	//bind the socket to our specified IP and port
	bind(server_socket, struct sockaddr*) &server_address, sizeof(server_address));

	//listens for connections (socket_name, backlog)
	listen(serverSocket, 1);

	
	//integer to hold client socket
	int clientSocket;
	
	//accept statement (server_socket, structs_that_contain_client_address)
	clientSocket = accept(serverSocket, NULL, NULL);

	//sends data (client_socket, data_to_send, sizeof(data_to_send), flag)
	send(clientSocket, serverMessage, sizeof(serverMessage), 0);

	//closes the socket
	close(serverSocket);

	return 0;
}
