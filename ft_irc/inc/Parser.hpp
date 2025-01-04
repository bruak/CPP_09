#pragma once

#include "Command.hpp"
#include "Client.hpp"
#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class ACommand;
#define WHITESPACES " \n\r\t\f\v"
#define ISFIND string::npos


class Parser {

    public:
        Parser(Server* server);
        ~Parser();

        void ParsAndExec(Client* client);
        string removWhiteSpac(const string &str);
    private:
        map<string, ACommand* > _MapCommads;

        Pass _passCommand;
        Nick _nickCommand;
        User _userCommand;
        Join _joinCommand;
        PrivMsg _privMsgCommand;
        Who _whoCommand;
        Mode _modeCommand;
        Notice _noticeCommand;
        Cap _capCommand;
        Part _partCommand;
        Kick _kickCommand;
        Quit _quitCommand;
        Bot _botCommand;

};
