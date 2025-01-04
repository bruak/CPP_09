#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie() { std::cout << this->Name << ": is dead :) like a philo" << std::endl; }

void Zombie::announce(void) { std::cout << this->Name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::add_name_for_private_variable(std::string incomingName) { this->Name = incomingName; }
