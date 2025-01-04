#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#ifndef NULL
#define NULL 0
#endif

Intern::Intern(){
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &cpy){

	std::cout << "Intern Copy Constructor" << std::endl;
	*this = cpy;
}
Intern::~Intern(){
	std::cout << "Intern Deconstructor" << std::endl;

}

Intern &Intern::operator=(const Intern &src){
    std::cout << "Intern, Copy assignment operator" << std::endl;
	if (this == &src)
		return *this;

	return *this;
}

static Form *makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form *makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string form_to_create, std::string target_for_form) {

	Form *(*all_forms[])(const std::string target) = {
		&makePresident,
		&makeRobot,
		&makeShrubbery
		};

	std::string forms[] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
		};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create << std::endl;
			return (all_forms[i](target_for_form));
		}
	}

	std::cerr << "\033[33mIntern can not create a form called " << form_to_create << "\033[0m" << std::endl;
	return (NULL);
}