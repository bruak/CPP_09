#include "Harl.hpp"

#define DEBUG "\n\033[1;36m[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\033[0m\n"
#define INFO "\n[INFO]\nI cannot believe adding extra bacon cost more money. You don’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
#define WARNING "\n\033[1;33m[WARNING]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\033[0m\n"
#define ERROR "\n\033[1;31m[ERROR]\nThis is unacceptable! I want to speak to the manager now.\033[0m\n"

Harl::Harl() {}

Harl::~Harl() {}	

void Harl::complain(std::string level) {

    std::string levels[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    int i = 0;
    while (level != levels[i])
        i++;

    switch (i)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
        default:
            break;
        }
}

void harlComplainsMessage(void) {

    std::cout << "HARL'S BURGER PROBLEM, DONT BE HARL\n";
    std::cout << " ____  _   _ ____   ____ _____ ____  \n"
                 "| __ )| | | |  _ \\ / ___| ____|  _ \\ \n"
                 "|  _ \\| | | | |_) | |  _|  _| | |_) |\n"
                 "| |_) | |_| |  _ < | |_| | |___|  _ < \n"
                 "|____/ \\___/|_| \\_\\ \\____|_____|_| \\_\\\"\n";
    std::cout << "\nMANUEL\n";
    std::cout << "\033[1;36m[DEBUG]\033[0m\n" << DEBUG;
    std::cout << "[INFO]\n" << INFO;
    std::cout << "\033[1;33m[WARNING]\033[0m\n" << WARNING;
    std::cout << "\033[1;31m[ERROR]\033[0m\n" << ERROR;
}

void Harl::debug(void) { std::cout << DEBUG; }

void Harl::info(void) { std::cout << INFO; }

void Harl::warning(void) { std::cout << WARNING; }

void Harl::error(void) { std::cout << ERROR; }
