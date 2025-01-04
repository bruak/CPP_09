#include "Zombie.hpp"

Zombie::	Zombie(std::string incomingName)
{
	this->Name = incomingName;
}

Zombie::~Zombie()
{
	std::cout << this->Name << ": is dead :) like a philo" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

