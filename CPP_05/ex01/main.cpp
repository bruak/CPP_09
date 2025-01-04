#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <stdexcept>

int main() {
	{
		std::cout << "\033[35mTEST 01\033[0m" << std::endl;
CONSTRUCTING
		Bureaucrat *a = new Bureaucrat(150);
		Form *b = new Form((std::string)"rent contrat");
JUST_NEW_LINE
TESTING
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		try {
			b->beSigned(*a);
		} catch(Bureaucrat::GradeTooLowException &e) {
			std::cerr << a->getName() << ", was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

JUST_NEW_LINE
DECONSTRUCTING
		delete a;
		delete b;
JUST_NEW_LINE
	}

	{
		std::cout << "\033[35mTEST 02\033[0m" << std::endl;
CONSTRUCTING
		Bureaucrat *a = new Bureaucrat(1);
		Form *b = new Form((std::string)"rent contrat");
JUST_NEW_LINE
TESTING
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		try {
			a->signForm(*b);
		} catch(Bureaucrat::GradeTooLowException &e) {
			std::cerr << a->getName() << ", was not able to sign " << b->getName() << ": " << e.what() << std::endl;
		}

JUST_NEW_LINE
DECONSTRUCTING
		delete a;
		delete b;
	}
JUST_NEW_LINE
	return (0);
}
