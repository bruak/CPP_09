#include "../../inc/Channel.hpp"
#include "../../inc/IrcResponseMacros.hpp"
#include "../../inc/Colors.hpp"
#include <algorithm>

using namespace std;

Channel::Channel(Client const &client, string const Name, string const passwd)
		:_Name(Name), _Passwd(passwd), _ClientLimit(100)
{
	_Clients.insert(pair<string, Client>("@" + client.GetNickname(), client));
}

void Channel::AddClient(Client &client)
{
	_Clients.insert(pair<string, Client>(client.GetNickname(), client));
}

void Channel::RemoveClient(Client &client)
{
	if (_Clients.find(client.GetNickname()) != _Clients.end())
		_Clients.erase(client.GetNickname());
	else if(_Clients.find("@" + client.GetNickname()) != _Clients.end())
		_Clients.erase("@" + client.GetNickname());
}

void Channel::AddBan(Client &client)
{
	_BanList.push_back(client);
}

void Channel::RemoveBan(Client &client)
{
	_BanList.erase(remove(_BanList.begin(), _BanList.end(), client), _BanList.end());
}

void Channel::AddInvite(Client &client)
{
	_InviteList.push_back(client);
}

void Channel::RemoveInvite(Client &client)
{
	_InviteList.erase(remove(_InviteList.begin(), _InviteList.end(), client), _InviteList.end());
}

void Channel::SetPasswd(string passwd)
{
	_Passwd = passwd;
}

string Channel::GetPasswd() const
{
	return _Passwd;
}

vector<Client> Channel::GetBanList() const
{
	return _BanList;
}

vector<Client> Channel::GetInviteList() const
{
	return _InviteList;
}


string Channel::GetName() const {
	return _Name;
}

bool Channel::operator==(Channel const &oder)
{
	return oder._Name == _Name;
}

bool Channel::operator!=(Channel const &oder)
{
	return oder._Name != _Name;
}

void Channel::BroadcastforChannelUsers(const string &BroadcastMsg) {

	map<string, Client>::iterator BeginIT = _Clients.begin();
	map<string, Client>::iterator EndIT = _Clients.end();
	while (BeginIT != EndIT)
	{
		BeginIT->second.MsgToClient(BroadcastMsg);
		BeginIT++;
	}
}

string Channel::GetUsers()
{
	map<string, Client>::iterator BeginIT = _Clients.begin();
	map<string, Client>::iterator EndIT = _Clients.end();
	string users = "";

	while (BeginIT != EndIT) {
		users.append(BeginIT->first + " ");
		BeginIT++;
	}
	return users;
}

Client *Channel::GetClients(string const &name) {
	if (_Clients.find(name) != _Clients.end())
		return	&_Clients.find(name)->second;
	else if(_Clients.find("@" + name) != _Clients.end())
		return	&_Clients.find("@" + name)->second;
	return NULL;
}

void Channel::AddOperator(const string& nickname) {
	string opNickname = "@" + nickname;
	if (_Clients.find(opNickname) == _Clients.end()) {
		map<string, Client>::iterator it = _Clients.find(nickname);
		if (it != _Clients.end()) {
			Client client = it->second;
			_Clients.erase(it);
			_Clients.insert(pair<string, Client>(opNickname, client));
		} else
			cout << RED << "Client not found: " << nickname << RESET << endl;
	} else
		cout << RED << "Operator already OP: " << nickname << RESET << endl;


}

void Channel::RemoveOperator(const string& nickname) {
	string opNickname = "@" + nickname;
	map<string, Client>::iterator it = _Clients.find(opNickname);
	if (it != _Clients.end()) {
		Client client = it->second;
		_Clients.erase(it);
		_Clients.insert(pair<string, Client>(nickname, client));
		cout << GREEN << "Operator removed: " << nickname << RESET << endl;
	} else {
		cout << RED << "Operator not found: " << nickname << RESET << endl;
	}
}

bool Channel::IsOperator(const string& nickname) {
	return _Clients.find("@" + nickname) != _Clients.end();
}

bool Channel::IsUserInChannel(const string& nickname) const {
	return _Clients.find(nickname) != _Clients.end() || _Clients.find("@" + nickname) != _Clients.end();
}

void Channel::SetChannelLimit(int limit) {
	if (limit < 0) {
		throw std::invalid_argument("Channel limit cannot be negative");
	}
	_ClientLimit = limit;
}

int Channel::GetChannelLimit() const {
	return _ClientLimit;
}
