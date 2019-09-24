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

//TODO: LEFTOFF on replacing parse args with method
int main(int argc, char** argv)
{
	/**
		Check command line arguments
	**/
	if(argc < 2)
	{
		fprintf(stderr, "Usage: ./httpclient [address]:[port] [REQUEST]\n");//--change later
		exit(EXIT_FAILURE);
	}

	/**
		Parse server address and port number and create socket.
	**/
	char* serverAddress = NULL;
	int serverPortNumber;
	parseArgvStrings(argv[1], &serverAddress, &serverPortNumber);
	struct sockaddr_in addr = createSockaddr(serverAddress, serverPortNumber);


















	return 0;
}
