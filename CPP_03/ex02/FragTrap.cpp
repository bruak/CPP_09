#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap default constructor" << std::endl;
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attacDamage = 30;
    this->name = "default";
}

FragTrap::FragTrap(std::string name){
    std::cout << "FragTrap default constructor" << std::endl;
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attacDamage = 30;
    this->name = name;
}

FragTrap::FragTrap(const FragTrap &copy){
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = name;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copyAssagment){
    std::cout << "Copy assignment operator" << std::endl;

    this->hitPoint = copyAssagment.hitPoint;
    this->attacDamage = copyAssagment.attacDamage;
    this->energyPoint = copyAssagment.energyPoint;
    this->name = copyAssagment.name;
    
    return *this;
}

void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << this->name << " positive high five :D" << std::endl;
}