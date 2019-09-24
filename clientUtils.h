//Header file for clientUtils.cpp

void parseArgvStrings(char* serverInfo, char** serverAddress, int* serverPort);

struct sockaddr_in createSockaddr(char* serverAddress, int portNumber);
