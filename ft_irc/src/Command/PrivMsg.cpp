#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

PrivMsg::PrivMsg(Server *server) : ACommand(server) {}

PrivMsg::~PrivMsg() {}

void PrivMsg::exec(Client *client, vector<string> &token)
{
	if (client->GetClientStatus() != REGISTERED)
	{
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 3) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "PRIVMSG"));
		return;
	}
	if (token[1][0] == '#') {
		Channel *channle = _srvObj->GetChannel(token[1]);
		if (!channle) {
			client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNickname(),token[1]));
			return;
		}
		else {
			if (!channle->IsUserInChannel(client->GetNickname())) {
				client->MsgToClient(ERR_CANNOTSENDTOCHAN(client->GetNickname(),token[1]));
				return;
			}
			map<string, Client>::iterator BeginIT = channle->GetClients().begin();
			map<string, Client>::iterator EndIT = channle->GetClients().end();
			while (BeginIT != EndIT) {
				if (BeginIT->second.GetFd() == client->GetFd()) {
					BeginIT++;
					continue;
				}
				BeginIT->second.MsgToClient(RPL_PRIVMSG(client->GetNamePrefix(),token[1],token[2]));
				BeginIT++;
			}
		}
	}
	else {
		Client *target = _srvObj->GetClients(token[1]);
		if (target)
		{
			target->MsgToClient(RPL_PRIVMSG(client->GetNamePrefix(), token[1] , token[2]));
		}
		else
			client->MsgToClient(ERR_NOSUCHNICK(client->GetNamePrefix(),token[2]));

	}
}
