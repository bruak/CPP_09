#include "Harl.hpp"

#define USAGE std::cout << "Usage: " << av[0] << " before input a value, when u run the program will se the manuel" << std::endl

int main(int ac, char *av[]){
    Harl harl;
    std::string level;

    if (ac != 1)
        return (USAGE), 1;       
    else {
        harlComplainsMessage();
        std::cin >> level;
           

        harl.complain(level);
    }
 

 
    return (0);
}
