#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char** av) {
    if (ac != 2)
        std::cerr << "arg err" << std::endl;
    else
        ScalarConverter example(av[1]);
}
