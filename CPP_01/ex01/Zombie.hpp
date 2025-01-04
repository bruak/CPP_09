#include <iostream>
#include <string>

#define ALLOC_ERR "ALLOC ERROR"

class Zombie
{
	private:
		std::string Name;

	public:
		Zombie();
		~Zombie();
	
		void add_name_for_private_variable(std::string incomingName);
		void announce(void);
};

Zombie *zombieHorde(int N, std::string name);
void add_name_for_all_zombies(int N, Zombie *too_many_zombies_address, std::string name);
