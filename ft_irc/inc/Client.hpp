#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Channel;

enum Status {
	HANDSHAKE,
	LOGIN,
	REGISTERED,
};

class Client {

	public:
		Client(int fd, int port, const string &hostname);
		~Client();


		int GetFd() const { return _Fd; }
		int GetPort() const { return _Port; }


		string GetNickname() const { return _nickname; }
		string GetUsername() const { return _username; }
		string GetRealname() const { return _realname; }
		string GetHostname() const { return _hostname; }
		string GetBuffer()  { return _buffer; }
		string GetNamePrefix() const;

		void setServername(const string &servername) { _servername = servername; }
		void setNickname(const string &nickname) { _nickname = nickname; }
		void setUsername(const string &username) { _username = username; }
		void setRealname(const string &realname) { _realname = realname; }
		void setHostname(const string &hostname) { _hostname = hostname; }
		void AddBuffer(const string &buffer) { _buffer.append(buffer); }
		void SetBuffer(const string &buffer) { _buffer = buffer; }
		Status GetClientStatus() const { return _ClientStatus; }
		void SetClientStatus(Status NewClientStatus);
		void ClearBuffer() { _buffer = ""; }
		void MsgToClient(const string &talk);

		bool operator !=(const Client &client);
		bool operator ==(const Client &client);

	private:
		int _Fd;
		int _Port;

		string _nickname;
		string _username;
		string _realname;
		string _hostname;

		string _servername;

		string _buffer;
		Status _ClientStatus;
};
