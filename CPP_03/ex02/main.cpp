#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{

    std::cout << "\033[34mDefault constructor test\033[0m" << std::endl;
    FragTrap frag1;
    frag1.highFivesGuys();

    std::cout << "\033[34mParameterized constructor test\033[0m" << std::endl;
    FragTrap frag2("FR4G");
    frag2.highFivesGuys();

    std::cout << "\033[34mCopy constructor test\033[0m" << std::endl;
    FragTrap frag3(frag2);
    frag3.highFivesGuys();

    std::cout << "\033[34mAssignment operator test\033[0m" << std::endl;
    FragTrap frag4;
    frag4 = frag2;
    frag4.highFivesGuys();

    std::cout << "\033[34mTest attack, takeDamage, and beRepaired functions\033[0m" << std::endl;
    frag2.attack("target");
    frag2.takeDamage(20);
    frag2.beRepaired(10);
    
    {
        std::cout << "\033[34mTesting\033[0m" << std::endl;
    
        FragTrap humans("HUMANS");
        FragTrap bandits("BANDITS");
        humans.attack("BANDITS");
        humans.takeDamage(101);
        humans.takeDamage(1);
        humans.beRepaired(5);
        humans.highFivesGuys();


    }

   
}