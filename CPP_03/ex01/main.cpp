#include "ScavTrap.hpp"

int main()
{
    std::cout << "\033[34mCreating ScavTrap instances\033[0m" << std::endl;
    ScavTrap humans("HUMANS");
    ScavTrap bandits("BANDITS");

    std::cout << "\033[34mHumans attacking Bandits\033[0m" << std::endl;
    humans.attack("BANDITS");
    humans.attack("BANDITS");

    std::cout << "\033[34mHumans taking damage\033[0m" << std::endl;
    humans.takeDamage(100);
    humans.takeDamage(20);

    std::cout << "\033[34mHumans being repaired\033[0m" << std::endl;
    humans.beRepaired(5);

    std::cout << "\033[34mHumans guarding gate\033[0m" << std::endl;
    humans.guardGate();

{
    std::cout << "\033[34mTESTING\033[0m" << std::endl;

    ScavTrap humans("HUMANS");
    ScavTrap bandits("BANDITS");
    humans.attack("BANDITS");
    humans.attack("BANDITS");
    humans.takeDamage(100);
    humans.takeDamage(20);
    humans.beRepaired(5);
    humans.guardGate();
}

}