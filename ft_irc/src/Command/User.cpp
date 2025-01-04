#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

User::User(Server* server) : ACommand(server) {}

User::~User() {}

void User::exec(Client* client, vector<string> &token) {
	if (client->GetClientStatus() < LOGIN || client->GetNickname().empty())
	{
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 5) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "USER"));
		return;
	}
	client->setUsername(token[1]);
	client->setHostname(token[2]);
	client->setServername(token[3]);
	client->setRealname(token[4]);
	client->MsgToClient(RPL_WELCOMEMESSAGE(client->GetNickname()));
	client->MsgToClient(RPL_WELCOME_MSG(client->GetNickname(),client->GetNickname()));
	client->SetClientStatus(REGISTERED);
}
