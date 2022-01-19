#include <iostream>
#include <WS2tcpip.h>
#include <winsock2.h>
//PuTTY is used to use a Secure Shell(SSH), which is a remote administration protocol allowing users to simulate/control/modify the remote server. 
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
		cerr << "Can't make a listening socket! Exiting...." << endl;
		return;
	}
	//Bind ip address and port to a socket
	sockaddr_in hint;
	hint.sin_family = AF_INET;

	// note to self: Networking run by 'big-endian' AKA ' the most significant figure in the  sequence of bytes is stord first, where little-endian has most sig. value is stored first.
	// this difference is countered using 'host to network short' aka htons
	hint.sin_port = htons(54000); // converts u_short from host byte order to TCP/IP network byte order.
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // also use inet_pton which converts IPv4 to IPv6

	bind(listener, (sockaddr*)&hint, sizeof(hint));
	// Tell Winsock the socket is for listening
	listen(listener, SOMAXCONN); //marks it as for listening, doesn't accept any connections. Also, SOMAXCONN is 2147483647 in decimal form, or 0x7fffffff in hex. Computer uses hex

	//Wait for connection
	sockaddr_in client;
	int clientSize = sizeof(client);

	SOCKET clientSocket = accept(listener, (sockaddr*)&client, &clientSize); //the socket that returns the value here is some random numbered socket, not our 54000
	if (clientSocket == INVALID_SOCKET)
	{
		cerr << "Can't make the client socket! Exiting..." << endl;
		return;
	}

	char host[NI_MAXHOST]; // holds client's remote name
	char service[NI_MAXSERV]; // Service (i.e. port) the client is connected on

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV); // set these variables to 0. you could replace these with memset(host, 0, NI_MAXHOST) if you're on mac or linux

	if (getnameinfo((sockaddr*)&client, clientSize, host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) // this is a long one, but to break it down...
		// we put in the socket address we are using. then the size of that address. Then we bring in the node's name followed by it's size. Then the service's name and size.
		// Finally, with the flag of 0, which means no special thing. You know, nothing. if getnameinfo returns 0, then the function completed successfully!
	{
		cout << host << " connected on port " << service << endl;
	}

	else 
	{
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST); // converts ip4/6  internet network address into a string in internet standard format 
		cout << host << " connected on port " << ntohs(client.sin_port) << endl; // changes a u_short from TCP/IP network byte order into a host byte order
	}
	// close listening socket
	closesocket(listener);
	//while : aceept, echo msg to client
	char buf[4096]; // buffer that is responsible for the incoming message

	while (true)
	{
		ZeroMemory(buf, 4096);

		//wait for the data sent by the client
		int bytesReceived = recv(clientSocket, buf, 4096, 0);

		if (bytesReceived == SOCKET_ERROR)
		{
			cerr << " The 'recv' function encountered an error! Exiting the program." << endl;
			break;
		}

		else if (bytesReceived == 0) // client disconnected
		{
			cout << "The client has disconnected, so the messages can no longer be echoed back!" << endl;
			break;
		}

		

		//repeat the message back to client!
		else
		{
			send(clientSocket, buf, bytesReceived + 1, 0); // length is like this due to us not getting the terminating 0 when receiving a message
		}
	}
	// close the sock
	closesocket(clientSocket);
	 

	//clean up winsock to prevent data leaks!
	WSACleanup();
}