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

	if (listener == INVALID_SOCKET) // socket doesn't initialize properly...
	{ 
		cerr << "Can't make a socket! Exiting...." << endl;
		return;
	}
	//Bind ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;

	// note to self: Networking run by 'big-endian' AKA ' the most significant figure in the  sequence of bytes is stord first, where little-endian has most sig. value is stored first.
	// this difference is countered using 'host to network short' aka htons
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = 
	// Tell Winsock the socket is for listening

	//Wait for connection

	// close listening socket

	//while : aceept, echo msg to client

	// clost the sock

	 

	//shutdown winsock to prevent data leaks!
}