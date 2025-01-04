#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Kick::Kick(Server *server) : ACommand(server) {}

Kick::~Kick() {}

void Kick::exec(Client *client, vector<string> &token) {
	if (client->GetClientStatus() != REGISTERED) {
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 4) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "KICK"));
		return ;
	}
	Channel *channel = _srvObj->GetChannel(token[1]);
	if (channel == NULL) {
		client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNamePrefix(),token[1]));
		return;
	}
	if (channel->IsOperator(client->GetNickname()) == false) {
		client->MsgToClient("481 Permission Denied: You must be an operator to use KICK command");
		return;
	}
	if (!_srvObj->GetClients(token[2])) {
		client->MsgToClient(ERR_NOSUCHNICK(client->GetNamePrefix(),token[1]));
		return;
	}
	Client *target = channel->GetClients(token[2]);
	if (!target) {
		client->MsgToClient(ERR_USERNOTINCHANNEL(client->GetNamePrefix(), token[2], token[1]));
		return;
	}
	channel->BroadcastforChannelUsers(RPL_KICK(client->GetNamePrefix(),token[1], token[2], token[3]));
	channel->RemoveClient(*target);
	if (channel->GetClients().size() == 0) {
		_srvObj->RemoveChannel(*channel);
		return;
	}
	channel->BroadcastforChannelUsers(RPL_NAMREPLY(client->GetNamePrefix(), token[1], channel->GetUsers()));
	channel->BroadcastforChannelUsers(RPL_ENDOFNAMES(client->GetNamePrefix(),token[1]));
}
