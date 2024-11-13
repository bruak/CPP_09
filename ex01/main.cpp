#include "RPN.hpp"
int main(int ac, char **av) {
	if (ac != 2) 
		return std::cerr << ARG_ERROR << std::endl, 1;
		
	try {
		RPN rpn(av[1]);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}