#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) {weapon = NULL, this->name = name;}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }

void HumanB::attack() { std::cout << name << " attacks with their " << weapon->getType() << std::endl; }
