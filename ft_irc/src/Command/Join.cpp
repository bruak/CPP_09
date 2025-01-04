#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

#define MAX_TOKEN_SIZE_FOR_IRC_STANDARTS 200

Join::Join(Server *server) : ACommand(server) {}

Join::~Join() {}

void Join::exec(Client *client, vector<string> &token)
{
	string password;
	Channel *channel;
	if (client->GetClientStatus() != REGISTERED) {
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 2) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "JOIN"));
		return ;
	}

	if (token.size() >= 3)
		password = token[2];
	else
		password = "";

	if (token[1][0] != '#' || (token[1].size() <= 1 && token[1].size() > MAX_TOKEN_SIZE_FOR_IRC_STANDARTS)) {
		client->MsgToClient(ERR_BADCHANMASK(client->GetNickname(), token[1]));
		return;
	}
	channel = _srvObj->GetChannel(token[1]);
	if (channel) {
		if (channel->GetClients(token[1])) {
			client->MsgToClient(ERR_USERNOTINCHANNEL(client->GetNamePrefix(),client->GetNickname(),token[1]));
			return ;
		}
		if (channel->GetPasswd() != password) {
			client->MsgToClient(ERR_BADCHANNELKEY(client->GetNamePrefix(),token[1]));
			return;
		}
		if (channel->GetClients().size()  >=  channel->GetLimit()) {
			client->MsgToClient(ERR_CHANNELISFULL(client->GetNamePrefix(),token[1]));
			return;
		}
		channel->AddClient(*client);
	} else 	{
		channel = new Channel(*client, token[1], password);
		_srvObj->AddChannel(channel);
	}
	channel->BroadcastforChannelUsers(RPL_JOIN(client->GetNamePrefix(), token[1]));
	client->MsgToClient(RPL_NAMREPLY(client->GetNamePrefix(), token[1], channel->GetUsers()));
	client->MsgToClient(RPL_ENDOFNAMES(client->GetNamePrefix(), token[1]));
}
