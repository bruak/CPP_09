#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name ){

    Zombie *too_many_zombies_address = new Zombie[N];

    return add_name_for_all_zombies(N, too_many_zombies_address, name), too_many_zombies_address;
}

void add_name_for_all_zombies(int N, Zombie *too_many_zombies_address, std::string name)
{
    for (int i = 0; i < N; i++) { too_many_zombies_address[i].add_name_for_private_variable(name); }
}
