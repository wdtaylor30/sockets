#if 0
William Daniel Taylor
2/26/18
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

	char *address;
	address = argv[1];

	//socket
	int clientSocket;
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	//connect to an address
	struct sockaddr_in remote_address;
	remote_address.sin_family = AF_INET;
	remote_address.sin_port = htons(80);

	/*converts string address to address structure
	(initial_address, where_to_store) */
	inet_aton(address, &remote_address.sin_addr.s_addr);

	//connect
	connect(clientSocket, (struct sockaddr *) &remote_address, sizeof(remote_address));

	//request and response
	char request[] = "GET / HTTP/1.1\r\n\r\n";
	char response[4096];

	//send and recieve
	send(clientSocket, request, sizeof(request), 0);
	recv(clientSocket, &response, sizeof(response), 0);

	//print result and close
	printf("Response from the server: %s\n", response);
	close(clientSocket);

	return 0;

}

