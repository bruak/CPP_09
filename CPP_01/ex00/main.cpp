#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	zombie = newZombie("Heap Zombie");
	zombie->announce();
	delete zombie;

	std::cout << "*********************************" << std::endl;

	randomChump("Stack Zombie");
	return (0);
}
