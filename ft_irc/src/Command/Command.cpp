#include "../../inc/Command.hpp"

ACommand::~ACommand() {}

ACommand::ACommand(Server* server) : _srvObj(server) {}
