#if 0
William Daniel Taylor
24 February 2018
Basic HTTP Server
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
	//pointer to store html data
	FILE *htmlData;
	
	//open file (file, (r)ead_or_(w)rite)
	htmlData = fopen("index.html", "r");

	//string to store html
	char responseData[1024];
	
	//read from file (where_to_read_data, size, file_to_read_from)
	fgets(responseData, 1024, htmlData);


	//response header
	char httpHeader [2048] = "HTTP/1.1 200 OK\r\n\n";

	//concatenation function
	strcat(httpHeader, responseData);


	//create a socket
	int serverSocket;
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	//define address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	bind(serverSocket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(serverSocket, 5);

	int clientSocket;
	while (1 == 1) {
		clientSocket = accept(serverSocket, NULL, NULL);
		send(clientSocket, httpHeader, sizeof(httpHeader), 0);
		close(clientSocket);
	}

	return 0;
}//end method
