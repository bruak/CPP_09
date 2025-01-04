#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string.h>

class ClapTrap
{
    private:
        std::string name;
        int hitPoint;
        int energyPoint;
        int attacDamage;
    
    public:
        ClapTrap();
        ClapTrap( std::string name );
        ClapTrap( const ClapTrap &copy );
        ~ClapTrap();
    
        ClapTrap &operator=( const ClapTrap &copyAssagment );
    
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif