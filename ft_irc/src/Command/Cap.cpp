#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Cap::Cap(Server *server) : ACommand(server) {}

Cap::~Cap() {}

void Cap::exec(Client *client, vector<string> &token)
{
	if (client->GetClientStatus() != REGISTERED)
	{
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 2)
		return (client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "CAP")));
	std::string cap = token[1];

	if (cap == "LS" || cap == "ls")
		client->MsgToClient("/BOT\n/PASS\n/USER\n/NICK\n/JOIN\n/PART\n/PRIVMSG\n/NOTICE\n/KICK\n/MODE\n/WHO\n/QUIT\n");
	else
		client->MsgToClient(ERR_INVALIDCAPCMD(client->GetNickname()));
}
