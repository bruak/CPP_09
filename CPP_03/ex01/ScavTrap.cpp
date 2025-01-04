#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){

    std::cout << "ScavTrap default constructor" << std::endl;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attacDamage = 20;
    name = "default";
}

ScavTrap::ScavTrap(std::string name){

    std::cout << "ScavTrap constructor" << std::endl;
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attacDamage = 20;
    this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap &copy){
    std::cout << "ScavTrap copy constructor" << std::endl;

    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copyAssagment){
    std::cout << "Copy assignment operator" << std::endl;
    
    this->hitPoint = copyAssagment.hitPoint;
    this->attacDamage = copyAssagment.attacDamage;
    this->energyPoint = copyAssagment.energyPoint;
    this->name = copyAssagment.name;
    
    return *this;
}

void ScavTrap::attack(const std::string& target){
    if (!(this->energyPoint <= 0 || this->hitPoint <= 0)) {
        std::cout << "ScavTrap " << this->name << " attacks " << target  << ", causing " << this->attacDamage << " points of damage!" << std::endl;
        this->energyPoint--;
    }
    else
        std::cout << "ScavTrap " << this->name << " has not enough point, energyPoint -> " << this->energyPoint << ", hitPoint -> " << this->hitPoint << std::endl; 
    return ;
}


void ScavTrap::guardGate(){

    std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}



ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor" << std::endl;
}