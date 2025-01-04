#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"
#include <algorithm>
#include <cstdlib>
Mode::Mode(Server *server) : ACommand(server) {}

Mode::~Mode() {}

void Mode::exec(Client* client, vector<string> &token)
{
	if (client->GetClientStatus() != REGISTERED) {
		client->MsgToClient(ERR_NOTREGISTERED(client->GetNickname()));
		return ;
	}
	if (token.size() < 4) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), " MODE "));
		return;
	}
	if (token[1][0] == '#') {
		std::string FirstTwo = token[2].substr(0, 2);
		if (FirstTwo == "+k") {
			Channel *Channel = _srvObj->GetChannel(token[1]);
			if (Channel != NULL)
				if (Channel->IsOperator(client->GetNickname())) {
					client->MsgToClient(RPL_MODE(client->GetNickname(), token[1], "+k ",  token[3]));
					Channel->SetPasswd(token[3]);
				}
				else
					client->MsgToClient(ERR_CHANOPRIVSNEEDED(client->GetNickname(), token[1]));
			else
				client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNickname(), token[1]));
		} else if (FirstTwo == "-k") {
			Channel *Channel = _srvObj->GetChannel(token[1]);
			if (Channel != NULL)
				if (Channel->IsOperator(client->GetNickname())) {
					client->MsgToClient(RPL_MODE(client->GetNickname(), token[1], "-k ",  ""));
					Channel->SetPasswd("");
				}
				else
					client->MsgToClient(ERR_CHANOPRIVSNEEDED(client->GetNickname(), token[1]));
			else
				client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNickname(), token[1]));
		} else if (FirstTwo == "+l") {
			Channel *Channel = _srvObj->GetChannel(token[1]);
			if (Channel != NULL)
				if (Channel->IsOperator(client->GetNickname())) {
					client->MsgToClient(RPL_MODE(client->GetNickname(), token[1], "+l ",  token[3]));
					Channel->SetChannelLimit(atoi(token[3].c_str()));
				}
				else
					client->MsgToClient(ERR_CHANOPRIVSNEEDED(client->GetNickname(), token[1]));
			else
				client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNickname(), token[1]));
		} else if (FirstTwo == "-l") {
			Channel *Channel = _srvObj->GetChannel(token[1]);
			if (Channel != NULL)
				if (Channel->IsOperator(client->GetNickname())) {
					client->MsgToClient(RPL_MODE(client->GetNickname(), token[1], "-l ",  ""));
					Channel->SetChannelLimit(MAX_CLIENTS);
				}
				else
					client->MsgToClient(ERR_CHANOPRIVSNEEDED(client->GetNickname(), token[1]));
			else
				client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNickname(), token[1]));
		} else if (FirstTwo == "+o") {
			Channel *channel = _srvObj->GetChannel(token[1]);
			if (channel != NULL) {
				if (channel->IsOperator(client->GetNickname()) && channel->IsUserInChannel(token[3])) {
					client->MsgToClient(RPL_MODE(client->GetNickname(), token[1], "+o ",  token[3]));
					channel->AddOperator(token[3]);
					channel->BroadcastforChannelUsers(RPL_NAMREPLY(client->GetNamePrefix(), token[1], channel->GetUsers()));
					channel->BroadcastforChannelUsers(RPL_ENDOFNAMES(client->GetNamePrefix(), token[1]));
				}
				else
					client->MsgToClient(ERR_CHANOPRIVSNEEDED(client->GetNickname(), token[1]));
			}
			else
				client->MsgToClient(ERR_NOSUCHCHANNEL(client->GetNickname(), token[1]));
		} else if (FirstTwo == "-o") {
			Channel *channel = _srvObj->GetChannel(token[1]);
			if (channel != NULL) {
				if (channel->IsOperator(client->GetNickname()) && channel->IsUserInChannel(token[3])) {
					client->MsgToClient(RPL_MODE(client->GetNickname(), token[1], "-o ",  token[3]));
					channel->RemoveOperator(token[3]);
					channel->BroadcastforChannelUsers(RPL_NAMREPLY(client->GetNamePrefix(), token[1], channel->GetUsers()));
					channel->BroadcastforChannelUsers(RPL_ENDOFNAMES(client->GetNamePrefix(), token[1]));
				}
				else
					client->MsgToClient(ERR_CHANOPRIVSNEEDED(client->GetNickname(), token[1]));
			}
		}
	}
}
