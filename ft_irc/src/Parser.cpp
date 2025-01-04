#include "../inc/Parser.hpp"
#include "../inc/Command.hpp"
#include "../inc/IrcResponseMacros.hpp"
#include "../inc/Colors.hpp"
#include <sstream>

Parser::Parser(Server *server)
	: _passCommand(server),
	_nickCommand(server),
	_userCommand(server),
	_joinCommand(server),
	_privMsgCommand(server),
	_whoCommand(server),
	_modeCommand(server),
	_noticeCommand(server),
	_capCommand(server),
	_partCommand(server),
	_kickCommand(server),
	_quitCommand(server),
	_botCommand(server)
{
	_MapCommads["PASS"] = &_passCommand;
	_MapCommads["NICK"] = &_nickCommand;
	_MapCommads["USER"] = &_userCommand;
	_MapCommads["JOIN"] = &_joinCommand;
	_MapCommads["PRIVMSG"] = &_privMsgCommand;
	_MapCommads["WHO"] = &_whoCommand;
	_MapCommads["MODE"] = &_modeCommand;
	_MapCommads["NOTICE"] = &_noticeCommand;
	_MapCommads["CAP"] = &_capCommand;
	_MapCommads["PART"] = &_partCommand;
	_MapCommads["KICK"] = &_kickCommand;
	_MapCommads["QUIT"] = &_quitCommand;
	_MapCommads["BOT"] = &_botCommand;
}

Parser::~Parser(){}

void Parser::ParsAndExec(Client* client)
{
	size_t pos;
	string  nonGapInput;
	vector<string> token;
	string command;
	string massage = client->GetBuffer();
	cout << YELLOW << massage << RESET <<  endl;
	while ((pos = massage.find("\n")) != ISFIND)
	{
		nonGapInput = massage.substr(0 ,pos + 1);
		stringstream streamForGl(nonGapInput);
		massage.erase(0, pos + 1);
		nonGapInput.clear();
		while (getline(streamForGl, nonGapInput, ' ')) {
			if(nonGapInput[0] == ':')
			{
				nonGapInput = nonGapInput.substr(1);
				getline(streamForGl, command);
				nonGapInput.append(" " + command);
			}
			nonGapInput = removWhiteSpac(nonGapInput);
			if (!nonGapInput.empty())
				token.push_back(nonGapInput);
			if (token.size() == 0)
				token.push_back("");
		}
		command = token[0];
		for (size_t i = 0; command[i]; i++)
			command[i] = toupper(command[i]);
		if (command[0] == '/')
			command = command.substr(1);
		map<string ,ACommand *>::iterator icom = _MapCommads.find(command);
		if (icom != _MapCommads.end())
			icom->second->exec(client, token);
		else {
			client->MsgToClient(ERR_UNKNOWNCOMMAND(client->GetNickname(), command));
			cout << RED << token[0] << ": command not found" << RESET << endl;
		}
		token.clear();
		if (pos == massage.size() - 1)
				break;
	}
}

string Parser::removWhiteSpac(const string &str) {
	string  res = "";

	size_t start = str.find_first_not_of(WHITESPACES);
	if (start != ISFIND)
		res = str.substr(start);

	size_t end = res.find_last_not_of(WHITESPACES);
	if (end != ISFIND)
		res = res.substr(0, end + 1);
	return res;
}
