#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << ERR_NO_ARG << std::endl;
		return 1;
	}
	try {
		MergeInsertSort sorter(argv);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
