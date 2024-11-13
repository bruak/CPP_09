#include "BitcoinExchange.hpp"
#include <iostream>


int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
	}

	try {
		Bit exchange;
		exchange.exchange(av[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}