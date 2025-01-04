#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Part::Part(Server *server) : ACommand(server) {}

Part::~Part() {}

void Part::exec(Client *client, vector<string> &token)
{
	if (client->GetClientStatus() != REGISTERED) {
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 2) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "PART"));
		return ;
	}
	Channel *channel = _srvObj->GetChannel(token[1]);
	if(channel) {
		channel->RemoveClient(*client);
		client->MsgToClient(RPL_PART(client->GetNamePrefix(),token[1]));
		channel->BroadcastforChannelUsers(RPL_NAMREPLY(client->GetNamePrefix(), token[1], channel->GetUsers()));
		channel->BroadcastforChannelUsers(RPL_ENDOFNAMES(client->GetNamePrefix(), token[1]));
		if (channel->GetClients().size() == 0)
			_srvObj->RemoveChannel(*channel);
		return ;
	}
	else {
		client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNamePrefix(), token[1]));
		return ;
	}
}
