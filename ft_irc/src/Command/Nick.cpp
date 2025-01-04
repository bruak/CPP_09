#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Nick::Nick(Server* server) : ACommand(server) {}

Nick::~Nick() {}

void Nick::exec(Client* client, vector<string> &token) {
	if (client->GetClientStatus() < LOGIN)
	{
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 2) {
		client->MsgToClient(ERR_NONICKNAMEGIVEN(client->GetNickname()));
		return ;
	}
	if (_srvObj->GetClients(token[1]))
	{
		client->MsgToClient(ERR_NICKNAMEINUSE(client->GetNamePrefix()));
		return ;
	}
	client->MsgToClient(RPL_NICK(client->GetNamePrefix(), token[1]));
	client->setNickname(token[1]);
}
