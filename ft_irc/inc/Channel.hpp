#pragma once

#include <iostream>
#include <map>
#include "Client.hpp"
#include <vector>

using namespace std;

class Channel
{
	private:
		string _Name;
		string _Passwd;
		long unsigned int _ClientLimit;

		map<string ,Client> _Clients;
		vector<Client> _BanList;
		vector<Client> _InviteList;

	public:

		Channel(Client const &client, string const Name, string const passwd = "");
		~Channel() {}


		void AddOperator(const std::string& nickname);
		void RemoveOperator(const std::string& nickname);

		bool operator==(Channel const &oder);
		bool operator!=(Channel const &oder);
		void AddClient(Client &client);
		void RemoveClient(Client &client);
		void AddBan(Client &client);
		void RemoveBan(Client &client);
		void AddInvite(Client &client);
		void RemoveInvite(Client &client);
		void SetPasswd(string passwd);
		string GetUsers();
		void BroadcastforChannelUsers(const string &BroadcastMsg);

		bool IsUserInChannel(const string& nickname) const;
		bool IsOperator(const string& nickname);

		void SetChannelLimit(int limit);
		int GetChannelLimit() const;

		string GetPasswd() const;
		Client	*GetClients(string const &name);
		map<string, Client> &GetClients() { return _Clients; }
		string GetName() const;
		long unsigned int GetLimit() { return _ClientLimit; }

		vector<Client> GetBanList() const;
		vector<Client> GetInviteList() const;

};
