#include "../../inc/Client.hpp"
#include "../../inc/Colors.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>

Client::Client(int fd, int port, const string &hostname) : _nickname(""), _username(""),_realname(""),_servername(""){
	_Fd = fd;
	_Port = port;
	_hostname = hostname;
	_ClientStatus = HANDSHAKE;
}

Client::~Client()
{}

void Client::SetClientStatus(Status NewClientStatus) {
	_ClientStatus = NewClientStatus;
}


bool Client::operator !=(const Client &client) {
	return _Fd != client.GetFd();
}

bool Client::operator ==(const Client &client) {
	return _Fd == client.GetFd();
}

void Client::MsgToClient(const string &talk) {
	string buf = talk + "\r\n";
	if (send(_Fd, buf.c_str(), buf.length(), 0) < 0) {
		cout << "Fd = " << _Fd << endl;
		throw runtime_error(RED "send error" RESET);
	}
}


string Client::GetNamePrefix() const {

	string prefix;
	string usname;

	if (_username.empty())
	 	usname = "";
	else
		usname = "!" + _username;

	string hostname;
	if (_hostname.empty())
		hostname = "";
	else
		hostname = "@" + _hostname;

	prefix = _nickname + usname + hostname;
	return prefix;
}
