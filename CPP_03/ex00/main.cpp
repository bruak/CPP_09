#include "ClapTrap.hpp"

int main()
{
    std::cout << "\033[34mCreating ClapTrap instances\033[0m" << std::endl;
    ClapTrap humans("HUMANS");
    ClapTrap bandits("BANDITS");

    std::cout << "\033[34mHumans attacking Bandits\033[0m" << std::endl;
    humans.attack("BANDITS");
    humans.attack("BANDITS");

    std::cout << "\033[34mHumans taking damage\033[0m" << std::endl;
    humans.takeDamage(10);
    humans.takeDamage(10);

    std::cout << "\033[34mHumans being repaired\033[0m" << std::endl;
    humans.beRepaired(5);

    std::cout << "\033[34mHumans attacking Another Bandit\033[0m" << std::endl;
    humans.attack("ANOTHER BANDIT");


    {
        std::cout << "\033[34mTESTING\033[0m" << std::endl;

        ClapTrap humans("HUMANS");
        ClapTrap bandits("BANDITS");

        humans.attack("BANDITS");
        humans.attack("BANDITS");
        humans.takeDamage(10);
        humans.takeDamage(10);
        humans.beRepaired(5);
        humans.attack("ANOTHER BANDIT");

        std::cout << "\033[34mBandits attacking Humans\033[0m" << std::endl;
        for (int i = 0; i < 12; i++)
            bandits.attack("HUMANS");

    }
}