#include <iostream>
#include <WS2tcpip.h>
#include <winsock2.h>

#pragma comment (lib, "ws2_32.lib") // tells the linker i need the library file in " " 's

using namespace std;

void main()
{
	 // first, initialize winsock
	WSADATA datasock;
	WORD ver = MAKEWORD(3, 0);

	int wsOK = WSAStartup(ver, &datasock);
	if (wsOK != 0)
	{
		cerr << "Unable to initialize winsock! Quitting out..." << endl;
		return;
	}
	// create socket for ip address and port to be bound to 

	SOCKET listener = socket(AF_INET, SOCK_STREAM, 0); //TCP sockets are opened via SOCK_STREAM or SOCK_DGRAM. 
	//Bind socket with ip address and port

	// Tell Winsock the socket is for listening

	//Wait for connection

	// close listening socket

	//while : aceept, echo msg to client

	// clost the sock

	 

	//shutdown winsock to prevent data leaks!
}