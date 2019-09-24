//clientUtils.cpp

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>


/**
  Sets serverAddress and serverPort to their respective command arg values.
**/
void parseArgvStrings(char* serverInfo, char** serverAddress, int* serverPort)
{
  *serverAddress = strtok(serverInfo, ":");
  char* serverPortStr = strtok(NULL, " ");
  if(*serverAddress == NULL || serverPortStr == NULL)
  {
    fprintf(stderr, "%s\n", "Error in parseArgvStrings: Could not parse server info.");
    exit(EXIT_FAILURE);
  }
  *serverPort = (int) atoi(serverPortStr);

  return; 
}

/**
  Create sockaddr
**/
struct sockaddr_in createSockaddr(char* serverAddress, int portNumber)
{
  struct hostent *hent = gethostbyname(serverAddress);
  if(hent == NULL)
  {
    herror("gethostbyname failed");
    exit(EXIT_FAILURE);
  }
  struct sockaddr_in addr;
  memcpy(&addr.sin_addr.s_addr, hent->h_addr, hent->h_length);
  addr.sin_port = htons(portNumber);
  addr.sin_family = AF_INET;
  return addr;
}

/**
  Get sock fd
**/
int getSockFd()
{
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0)
  {
    perror("getSockFd:");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}

/**
  Connect client to server.
**/
void serverConnect(int fd, struct sockaddr* addr, socklen_t addrlen)
{
  if((connect(fd, addr, addrlen)) < 0)
  {
    perror("connect() failed");
    exit(EXIT_FAILURE);
  }
}