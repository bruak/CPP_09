#pragma once

/* Error Responses */
#define ERR_NOTREGISTERED(source)                       "451 " + source + " :You have not registered"
#define ERR_ALREADYREGISTERED(source)                   "462 " + source + " :You may not register"
#define ERR_PASSWDMISMATCH(source)                      "464 " + source + " :Password is incorrect"
#define ERR_NONICKNAMEGIVEN(source)                     "431 " + source + " :Nickname not given"
#define ERR_NICKNAMEINUSE(source)                       "433 " + source + " " + source  + " :Nickname is already in use"
#define ERR_UNKNOWNCOMMAND(source, command)             "421 " + source + " " + command + " :Unknown command"
#define ERR_NEEDMOREPARAMS(source, command)             "461 " + source + " " + command + " :Not enough parameters"
#define ERR_NOSUCHCHANNEL(source, channel)              "403 " + source + " " + channel + " :No such channel"
#define ERR_BADCHANNELKEY(source, channel)              "475 " + source + " " + channel + " :Cannot join channel (+k)"
#define ERR_CHANNELISFULL(source, channel)              "471 " + source + " " + channel + " :Cannot join channel (+l)"
#define ERR_CANNOTSENDTOCHAN(source, channel)           "404 " + source + " " + channel + " :Cannot send to channel"
#define ERR_CHANOPRIVSNEEDED(source, channel)           "482 " + source + " " + channel + " :You’re not a channel operator on channel " + channel + " and cannot grant operator status"
#define ERR_BADCHANMASK(nickname, channel)              "476 " + nickname + " " + channel + ":Bad Channel Mask"
#define ERR_NOSUCHNICK(source, nickname)                "401 " + source + " " + nickname + " :No such nick/channel"
#define ERR_USERNOTINCHANNEL(source, nickname, channel) "441 " + source + " " + nickname + " " + channel + " :They aren't on that channel"
#define ERR_INVALIDCAPCMD(nickname)					 "410 " + nickname + " :Invalid CAP subcommand"

/* Numeric Responses */
#define RPL_WELCOME_MSG( nick, perfix)                  ": 001 " + nick + " :Welcome to the Internet Relay Network " + perfix
#define RPL_NAMREPLY(source, channel, users)            ": 353 " + source + " = " + channel + " :" + users
#define RPL_ENDOFNAMES(source, channel)                 ": 366 " + source + " " + channel + " :End of /NAMES list."

/* Command Responses */
#define RPL_JOIN(nick, channel)                         ":" + nick + " JOIN " + channel
#define RPL_PART(source, channel)                       ":" + source + " PART :" + channel
#define RPL_PRIVMSG(source, target, message)            ":" + source + " PRIVMSG " + target + " :" + message
#define RPL_NOTICE(source, target, message)             ":" + source + " NOTICE " + target + " :" + message
#define RPL_QUIT(source, message)                       ":" + source + " QUIT :Quit: " + message
#define RPL_KICK(source, channel, target, reason)       ":" + source + " KICK " + channel + " " + target + " :" + reason
#define RPL_WELCOMEMESSAGE(nickname)                    "Welcome to the server, " + nickname + "!"
#define RPL_NICK(source,nickname)                       ":" + source + " NICK " + nickname
#define RPL_MODE(source, channel, modes, args)          ":" + source + " MODE " + channel + " " + modes + " " + args
