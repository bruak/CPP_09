#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Who::Who(Server* server) : ACommand(server) {}

Who::~Who() {}

void Who::exec(Client* client, vector<string> &token) {
	Channel *channel;
	if (client->GetClientStatus() != REGISTERED)
	{
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 2) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNamePrefix(), "WHO"));
		return;
	}
	channel = _srvObj->GetChannel(token[1]);
	if (channel == NULL) {
		client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNamePrefix(), token[1]));
		return;
	}
	else
	{
		map<string, Client>::iterator it_b = channel->GetClients().begin();
		map<string, Client>::iterator it_e = channel->GetClients().end();
		while (it_b != it_e)
		{
			client->MsgToClient("* " + it_b->first);
			it_b++;
		}
	}

}
