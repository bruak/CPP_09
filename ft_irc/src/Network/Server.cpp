#include "../../inc/Server.hpp"
#include "../../inc/Parser.hpp"
#include "../../inc/Colors.hpp"
#include <iostream>
#include <algorithm>
int sig = 0;
#define SOCKET_CREATE_SUCCES cout << MAGENTA << "SOCKET CREATE SUCCESS" << RESET << endl;
#define SOCKET_CREATING cout << MAGENTA << "SOCKET CREATING" << RESET << endl;
#define POLL_IS_STARTING cout << GREEN << "Poll(), Server is starting" << RESET << endl;
#define CLIENT_DISCONNECTED cout << MAGENTA << "One client is disconnected" RESET << endl;
#define NEW_CLIENT_IS_CONNECTED cout << MAGENTA << "New Client is connected!!!!" << RESET << endl;
#define CHANNEL_NOT_FOUND cout << "Channel not found" << endl;

Server::Server(string Av1Port, string PassWord)
    : _parserObj(this), _PassWord(PassWord)
{
	for (size_t i = 0; Av1Port[i]; i++)
		if (!isdigit(Av1Port[i]))
			throw runtime_error(RED "Invalid PORT" RESET);
	GetAndPrintSystemIp();
	_Port = atoi(Av1Port.c_str());
	_ServerSocket = CreateSocket();
}

string Server::GetPasswd() {
	return _PassWord;
}

Server::~Server() {
	for (size_t i = 0; i < _VecPollFd.size(); i++)
		close(_VecPollFd[i].fd);
	for (size_t it = 0; it < _Clients.size(); it++)
		delete _Clients[it];
	for (vector<Channel *>::iterator it = _Channel.begin() ; it != _Channel.end(); it++)
		delete *it;
	close(_ServerSocket);
}

int Server::CreateSocket() {
SOCKET_CREATING

	if ((_ServerSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		throw runtime_error(RED "Socket() error" RESET);
	int opt = 1;
	if (setsockopt(_ServerSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
		throw runtime_error(RED "Setsocopt() error" RESET);

	memset(&_SocketAddr, 0, sizeof(_SocketAddr));
	_SocketAddr.sin_family = AF_INET;
	_SocketAddr.sin_addr.s_addr = INADDR_ANY;
	_SocketAddr.sin_port = htons(_Port);

	const sockaddr *soc_info_address = (struct sockaddr *)&_SocketAddr;
	socklen_t __len = sizeof(_SocketAddr);

	if (bind(_ServerSocket, soc_info_address, __len) < 0)
		throw runtime_error(RED "Bind() error, probably previus port is used." RESET);

	if (listen(_ServerSocket, MAX_CLIENTS_IN_QUEUE) < 0)
		throw runtime_error(RED "Listen() error" RESET);
SOCKET_CREATE_SUCCES
	return (_ServerSocket);
}

void Server::PollStart() {

	_PollFd.fd = _ServerSocket;
	_PollFd.events = POLLIN;
	_PollFd.revents = 0;
	_VecPollFd.push_back(_PollFd);

POLL_IS_STARTING

	while (sig == 0)
	{
		if (poll(_VecPollFd.data(), _VecPollFd.size(), -1) < 0)
		{
			if (errno == EINTR)
				continue;
			else if (errno == EWOULDBLOCK)
				continue;
			else if (errno == EINVAL) {
				cout << RED "Poll() error" RESET << endl;
				break;
			}
		}
		for (size_t i = 0; i < _VecPollFd.size(); i++)
		{
			if (_VecPollFd[i].revents == 0)
				continue;

			if ((_VecPollFd[i].revents & POLLHUP) == POLLHUP)
			{
				ClientIsDisconnect(_VecPollFd[i].fd);
				break;
			}

			if ((_VecPollFd[i].revents & POLLIN) == POLLIN)
			{
				if (_VecPollFd[i].fd == _ServerSocket)
				{
					ClientIsConnect();
					break;
				}
				ClientIsTexting(_VecPollFd[i].fd);
			}
		}
	}
}

void Server::ClientIsDisconnect(int ClientFd) {
	try {
		Client* client = GetClients(ClientFd);
		_Clients.erase(remove(_Clients.begin(), _Clients.end(), client), _Clients.end());
		size_t i = 0;
		while (i < _VecPollFd.size()) {
			if (_VecPollFd[i].fd == ClientFd) {
				_VecPollFd.erase(_VecPollFd.begin() + i);
				close(ClientFd);
				break;
			}
			i++;
		}
		delete client;
CLIENT_DISCONNECTED
	} catch (exception &e) {
		cout << RED "Client disconnect error-> " RESET << e.what() << endl;
	}
}

void Server::ClientIsTexting(int ClientFd) {
	try {
		Client* client = GetClients(ClientFd);
		string messsage = recv_message(ClientFd);
		client->AddBuffer(messsage);
		if (messsage.find("\n") != string::npos)
		{
			_parserObj.ParsAndExec(client);
			if (GetClients(ClientFd))
				client->ClearBuffer();
		}
	} catch (exception &e) {
		cout << RED << e.what() << RESET << endl;
	}
}

string Server::recv_message(int ClientFd) {
	string message;
	char buffer[1024] = {0};
	ssize_t len = 0;
	memset(buffer, 0, sizeof(buffer));

	while (true) {
		memset(buffer, 0, 1024);
		len = recv(ClientFd, buffer, 1024, 0);
		if (len < 0)
		{
			if (errno == EWOULDBLOCK)
				break;
			throw runtime_error(RED "recv() buffer error" RESET);
		}
		else if (len == 0)
		{
			ClientIsDisconnect(ClientFd);
			break;
		}
		message.append(buffer);
	}
	return (message);
}

void Server::ClientIsConnect() {
	int NewSocket;
	struct sockaddr_in addr = {};
	unsigned int size = sizeof(addr);

	NewSocket = (accept(_ServerSocket, (sockaddr *)&addr, &size));
	if (NewSocket < 0)
		throw runtime_error(RED "Accept() error" RESET);
	if (fcntl(NewSocket, F_SETFL, O_NONBLOCK) < 0)
		throw runtime_error(RED "Fcntl() error" RESET);

	_PollFd.fd = NewSocket;
	_PollFd.events = POLLIN | POLLHUP;
	_PollFd.revents = 0;
	_VecPollFd.push_back(_PollFd);

	char HostName[NI_MAXHOST];
	int res = getnameinfo((sockaddr *) &addr, sizeof(addr), HostName, NI_MAXHOST, NULL, 0, NI_NUMERICSERV);
	if (res != 0)
		throw runtime_error(RED "Getnameinfo() error" RESET);

	Client* newClient = new Client(NewSocket, ntohs(addr.sin_port), HostName);
	_Clients.push_back(newClient);
NEW_CLIENT_IS_CONNECTED
}

void Server::GetAndPrintSystemIp() {

	struct ifaddrs *interfaces = NULL;
	struct ifaddrs *tempAddr = NULL;

	if (getifaddrs(&interfaces) == -1)
		throw runtime_error("getifaddrs error");

	tempAddr = interfaces;
	while (tempAddr != NULL) {
		if (tempAddr->ifa_addr->sa_family == AF_INET) {
			char ipAddress[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, &((struct sockaddr_in *)tempAddr->ifa_addr)->sin_addr, ipAddress, INET_ADDRSTRLEN);
			cout << CYAN << "interface: " << tempAddr->ifa_name << " - IP: " << ipAddress << RESET << endl;
		}
		tempAddr = tempAddr->ifa_next;
	}
	freeifaddrs(interfaces);
}

void Server::AddChannel(Channel *channel) {
	_Channel.push_back(channel);
}



void Server::RemoveChannel(Channel const &channel)
{
	for (vector<Channel *>::iterator it = _Channel.begin(); it != _Channel.end(); ++it)
	{
		if (*it == &channel)
		{
			delete *it;
			_Channel.erase(it);
			return;
		}
	}
CHANNEL_NOT_FOUND
}

Channel *Server::GetChannel(string const &name) {
	for (vector<Channel *>::iterator it = _Channel.begin(); it != _Channel.end(); it++)
		if (!(*it)->GetName().compare(name))
			return *it;
	return NULL;
}

Client* Server::GetClients(string const &name) {
	for (size_t it = 0; it < _Clients.size() ; it++)
		if (_Clients[it]->GetNickname()== name)
			return _Clients[it];
	return NULL;
}

Client* Server::GetClients(int const &Fd) {
	for (size_t it = 0; it < _Clients.size() ; it++)
		if (_Clients[it]->GetFd() == Fd)
			return _Clients[it];
	return NULL;
}
