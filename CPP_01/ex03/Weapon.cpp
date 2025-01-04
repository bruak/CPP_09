#include "Weapon.hpp"

Weapon::Weapon(std::string const &weapon_type) { type = weapon_type; }

Weapon::~Weapon() {}

const std::string& Weapon::getType() { return type; }

void Weapon::setType(const std::string weapon_type){ type = weapon_type; }
