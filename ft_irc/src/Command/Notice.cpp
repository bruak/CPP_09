#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Notice::Notice(Server *server) : ACommand(server) {}

Notice::~Notice() {}

void Notice::exec(Client *client, vector<string> &token)
{
	if (client->GetClientStatus() != REGISTERED) {
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 3) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "NOTICE"));
		return ;
	}
	string target = token[1];
	string message = token[2];
	if (target[0] == '#') {
		Channel *channel = _srvObj->GetChannel(target);
		if (channel == NULL) {
			client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNickname(), "NOTICE"));
			return ;
		}
		if (!channel->IsUserInChannel(client->GetNickname())) {
			client->MsgToClient(ERR_CANNOTSENDTOCHAN(client->GetNickname(), "NOTICE"));
			return ;
		}
		map<string, Client>::iterator it_b = channel->GetClients().begin();
		map<string, Client>::iterator it_e = channel->GetClients().end();
		for (map<string, Client>::iterator it = it_b; it != it_e; it++) {
			it->second.MsgToClient(RPL_NOTICE(client->GetNamePrefix(), it->second.GetNickname(), message));
		}

	}
	else {
		Client *client = _srvObj->GetClients(target);
		if (client == NULL) {
			client->MsgToClient(ERR_NOSUCHNICK(client->GetNickname(), "NOTICE"));
			return ;
		}
		client->MsgToClient(RPL_NOTICE(client->GetNamePrefix(), client->GetNickname(), message));
	}
}
