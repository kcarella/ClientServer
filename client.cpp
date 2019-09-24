/**
** TODO: Add the appropiate headers here.
** TODO: Use bounded literal types
** TODO: Rename source file to httpclient and executable to client.
** TODO: Choose linter and styler.
**/

//for socket stuff
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

// TODO: Remove all comments below later.
// TODO: Use linter to verify that all libraries are used.

//for printf
#include<stdio.h>
//for exit
#include<stdlib.h>
//other
#include<unistd.h> 

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

// Constants & Utils
#include "clientConstants.h"
#include "clientUtils.h"

int main(int argc, char** argv)
{
	/**
		Check command line arguments
	**/
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s [Address]:[PortNumber] [REQUEST]\n", argv[0]);//--change later
		exit(EXIT_SUCCESS);
	}

	/**
		Parse server address and port number from argv and create socket.
	**/
	char* serverAddress = NULL;
	int serverPortNumber;
	parseArgvStrings(argv[1], &serverAddress, &serverPortNumber);
	struct sockaddr_in addr = createSockaddr(serverAddress, serverPortNumber);

	/**
	    Push/Handle requests one by one.
	**/
	for(int i = CMD_ARG_OFFSET; i < argc; i++)
	{
		int sockfd = getSockFd();
		serverConnect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

		//Send message to server
		int returnValue;
      	if((returnValue = send(sockfd, GREET, GREET_LEN, 0)) < 0)
      	{
        	perror("Writing to server failed:");
        	continue;
      	}

      	//close socket
      	close(sockfd);
	}




















	return 0;
}
