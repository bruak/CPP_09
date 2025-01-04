#pragma once

#include "Client.hpp"
#include "IrcResponseMacros.hpp"
#include <vector>
#include <string>

#define PRINT_ASCII_ART() "                                     ___    ,'\"\"\"\"\"'.\n                                    ,\"\"\"   \"\"\"\"'      `.\n                                   ,'        _.         `._\n                                  ,'       ,'              `\"\"\"'.\n                                 ,'    .-\"\"`.    ,-'            `.\n                                ,'    (        ,'                :\n                              ,'     ,'           __,            `.\n                        ,\"\"\"\"'     .' ;-.    ,  ,'  \\             `\"\"\"\".\n                      ,'           `-(   `._(_,'     )_                `.\n                     ,'         ,---. \\ @ ;   \\ @ _,'                   `.\n                ,-\"\"'         ,'      ,--'-    `;'                       `.\n               ,'            ,'      (      `. ,'                          `.\n               ;            ,'        \\    _,','                            `.\n              ,'            ;          `--'  ,'                              `.\n             ,'             ;          __    (                    ,           `.\n             ;              `____...  `78b   `.                  ,'           ,'\n             ;    ...----'''' )  _.-  .d8P    `.                ,'    ,'    ,'\n_....----''' '.        _..--\"_.-:.-' .'        `.             ,''.   ,' `--'\n              `\" mGk \"\" _.-'' .-'`-.:..___...--' `-._      ,-\"'   `-'\n        _.--'       _.-'    .'   .' .'               `\"\"\"\"\"\n  __.-''        _.-'     .-'   .'  /\n '          _.-' .-'  .-'        .'\n        _.-'  .-'  .-' .'  .'   /\n    _.-'      .-'   .-'  .'   .'\n_.-'       .-'    .'   .'    /\n       _.-'    .-'   .'    .'\n    .-'            .'\n"
#define PRINT_ASCII_ART2() "              .\n               					\n              |					\n     .               /				\n      \\       I     				\n                  /\n        \\  ,g88R_\n          d888(`  ).                   _\n -  --==  888(     ).=--           .+(`  )`.\n)         Y8P(       '`.          :(   .    )\n        .+(`(      .   )     .--  `.  (    ) )\n       ((    (..__.:'-'   .=(   )   ` _`  ) )\n`.     `(       ) )       (   .  )     (   )  ._\n  )      ` __.:'   )     (   (   ))     `-'.:(`  )\n)  )  ( )       --'       `- __.'         :(      ))\n.-'  (_.'          .')                    `(    )  ))\n                  (_  )                     ` __.:'\n                                        	\n--..,___.--,--'`,---..-.--+--.,,-,,..._.--..-._.-a:f--."

class Server;

class ACommand
{
	public:
		ACommand(Server* server);
		virtual ~ACommand() = 0;
		virtual void exec(Client* client, vector<string> &token) = 0;

	protected:
		Server *_srvObj;
};

class Pass : public ACommand
{
	public:
		Pass(Server* server);
		~Pass();
		void exec(Client* client, vector<string> &token);
};

class Nick : public ACommand
{
	public:
		Nick(Server* server);
		~Nick();
		void exec(Client* Client, vector<string> &token);
};

class User : public ACommand
{
	public:
		User(Server* server);
		~User();
		void exec(Client* Client, vector<string> &token);
};

 class Join : public ACommand
{
	public:
		Join(Server *server);
		~Join();
		void exec(Client* Client, vector<string> &token);
};

 class PrivMsg : public ACommand
{
	public:
		PrivMsg(Server *server);
		~PrivMsg();
		void exec(Client* Client, vector<string> &token);
};

 class Who : public ACommand
{
	public:
		Who(Server *server);
		~Who();
		void exec(Client* Client, vector<string> &token);
};
 class Mode : public ACommand
{
	public:
		Mode(Server *server);
		~Mode();
		void exec(Client *Client, vector<string> &token);
};

class Notice : public ACommand
{
	public:
		Notice(Server *server);
		~Notice();
		void exec(Client* Client, vector<string> &token);
};

class Cap : public ACommand
{
	public:
		Cap(Server *server);
		~Cap();
		void exec(Client* Client, vector<string> &token);
};

class Part : public ACommand
{
	public:
		Part(Server *server);
		~Part();
		void exec(Client* Client, vector<string> &token);
};

class Kick : public ACommand
{
	public:
		Kick(Server *server);
		~Kick();
		void exec(Client* Client, vector<string> &token);
};

class Quit : public ACommand
{
	public:
		Quit(Server *server);
		~Quit();
		void exec(Client* Client, vector<string> &token);
};

class Bot : public ACommand
{
	public:
		Bot(Server *server);
		~Bot();
		void exec(Client* Client, vector<string> &token);
	private:
		vector<string> facts;
};

