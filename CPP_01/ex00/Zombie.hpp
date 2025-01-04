#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string Name;

	public:
		Zombie(std::string incomingName);
		~Zombie();
		
		void announce(void);
};

		Zombie *newZombie(std::string name);
		void randomChump(std::string name);
