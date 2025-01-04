#include "Harl.hpp"

#define USAGE std::cout << "Usage: " << av[0] << " before input a value, when u run the program will se the manuel" << std::endl

int main(int ac, char *av[]){
    Harl harl;
    std::string level;

    if (ac != 2)
        return (USAGE), 1;
    
    level = static_cast<std::string>(av[1]);
    if (!level.compare("I am not sure how tired I am today...")) {
        std::cout << "I am not sure how tired I am today..." << std::endl;
        return (0);
    }
    else {
        harl.complain(av[1]);
    }
 

 
    return (0);
}
