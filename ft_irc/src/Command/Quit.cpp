#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Quit::Quit(Server *server) : ACommand(server) {}

Quit::~Quit() { }

void Quit::exec(Client *client, vector<string> &token) {
	if (token.size() == 1)
		token.push_back("");
	vector<Channel *>  vect = _srvObj->GetChannel();
	for (vector<Channel *>::iterator it = vect.begin(); it != vect.end(); it++)
	{
		if ((*it)->GetClients(client->GetNickname()))
		{
			(*it)->RemoveClient(*client);
			if ((*it)->GetClients().size() == 0)
			{
				_srvObj->RemoveChannel(*(*it));
				continue;
			}
			(*it)->BroadcastforChannelUsers(RPL_NAMREPLY(client->GetNamePrefix(), (*it)->GetName(), (*it)->GetUsers()));
			(*it)->BroadcastforChannelUsers(RPL_ENDOFNAMES(client->GetNamePrefix(), (*it)->GetName()));
		}
	}
	client->MsgToClient(RPL_QUIT(client->GetNickname(), token[1]));
	_srvObj->ClientIsDisconnect(client->GetFd());
}
