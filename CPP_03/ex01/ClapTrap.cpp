#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor" << std::endl;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attacDamage = 20;
    this->name = "default";
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "ClapTrap constructor" << std::endl;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attacDamage = 20;
    this->name = name;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &copy){
    std::cout << "ClapTrap copy constructor" << std::endl;

    *this = copy;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &copyAssagment) {
    std::cout << "Copy assignment operator" << std::endl;
    
    this->hitPoint = copyAssagment.hitPoint;
    this->attacDamage = copyAssagment.attacDamage;
    this->energyPoint = copyAssagment.energyPoint;
    this->name = copyAssagment.name;
    
    return *this;
}

void ClapTrap::attack( const std::string &target){
    if (!(this->energyPoint <= 0 || this->hitPoint <= 0)) {
        std::cout << "ClapTrap " << this->name << " attacks " << target  << ", causing " << this->attacDamage << " points of damage!" << std::endl;
        this->energyPoint--;
    }
    else
        std::cout << "ClapTrap " << this->name << " has not enough point, energyPoint -> " << this->energyPoint << ", hitPoint -> " << this->hitPoint << std::endl; 
    return ;
}

void ClapTrap::takeDamage( unsigned int amount){
    if (!(this->hitPoint <= 0) && this->hitPoint >= amount) {
        this->hitPoint -= amount;
        if (this->hitPoint < 0)
            this->hitPoint = 0;
        std::cout << "ClapTrap " << name << " has take " << amount << " amount of damage, now " << this->name << " has " << this-> hitPoint << " hitpoint" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has not enough point, hitpoint -> " << this->hitPoint << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount){
    if (!(this->energyPoint <= 0 || this->hitPoint <= 0)) {
        this->hitPoint += amount;
        this->energyPoint--;
        std::cout << "ClapTrap " << this->name << " has repair ourself for this amount points -> " << amount << " now has hitpoint is -> " << this->hitPoint << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has not enough point, energyPoint -> " << this->energyPoint << ", hitPoint -> " << this->hitPoint << std::endl;
    return ;
}