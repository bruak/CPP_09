#include "../../inc/Command.hpp"
#include "../../inc/Server.hpp"

Pass::Pass(Server *server) : ACommand(server) {}

Pass::~Pass() {}

void Pass::exec(Client* client, vector<string> &token) {
	if (token.size() < 2) {
		client->MsgToClient(ERR_NEEDMOREPARAMS(client->GetNickname(), "PASS"));
		return ;
	}
	if (client->GetClientStatus()) {
		client->MsgToClient(ERR_ALREADYREGISTERED(client->GetNickname()));
		return ;
	}
	if (_srvObj->GetPasswd() != token[1]) {
		client->MsgToClient(ERR_PASSWDMISMATCH(client->GetNickname()));
		return ;
	}
	client->SetClientStatus(LOGIN);
	client->MsgToClient("Password accepted");
}

