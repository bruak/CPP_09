#include "Zombie.hpp"

#define Zombie_num 3
#define ZombiesName "abdulzerrak"

int main()
{
	Zombie *zombie;
	zombie = zombieHorde(Zombie_num, ZombiesName);
	for (int i = 0; i < Zombie_num; i++) { zombie[i].announce(); }

	delete[] zombie;

	return (0);
}
