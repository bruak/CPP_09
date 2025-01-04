#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
    public:
        HumanB(std::string const &name);
        ~HumanB();


        void setWeapon(Weapon &weapon);
        void attack();
    
    private:
        std::string name;
        Weapon *weapon;
};

