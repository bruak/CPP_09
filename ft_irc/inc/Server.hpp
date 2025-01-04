#pragma once

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <poll.h>
#include <exception>

#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <cstdlib>
#include <fcntl.h>
#include <string>

#include <vector>
#include <map>
#include <cerrno>

#include "Parser.hpp"
#include "Colors.hpp"
#include "Channel.hpp"
#include "IrcResponseMacros.hpp"

using namespace std;
#define MAX_CLIENTS 100
#define MAX_CLIENTS_IN_QUEUE 100
typedef vector<string>::iterator str_it;

class Server {

	public:
		Server(string Av1Port, string _PassWord);
		~Server();

		int CreateSocket();
		void PollStart();
		void ClientIsDisconnect(int ClientFd);
		void ClientIsTexting(int ClientFd);
		void ClientIsConnect();
		void GetAndPrintSystemIp();

		vector<Channel *> GetChannel() const { return _Channel; }

		string recv_message(int ClientFd);

		void AddChannel(Channel  *channel);
		void RemoveChannel(Channel const &channel);
		vector<Client *> GetClients() { return _Clients; }

		string GetPasswd();
		Channel* GetChannel(string const &name);
		Client* GetClients(string const &name);
		Client* GetClients(int const &fd);
		vector<pollfd> GetPoll() { return _VecPollFd; }

	private:
		int _ServerSocket;
		int _Port;

		Parser	_parserObj;
		string _PassWord;

		struct sockaddr_in _SocketAddr;
		struct pollfd _PollFd;

		vector<Channel *> _Channel;
		vector<pollfd> _VecPollFd;
		vector<Client *> _Clients;
};

