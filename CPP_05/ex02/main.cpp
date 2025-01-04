#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <stdexcept>

void testPresidentialPardonForm() {
	{
TESTING
CONSTRUCTING
			Bureaucrat bureaucrat("John Doe", 1);
    	    PresidentialPardonForm form("Target A");

    	try {
    	    form.beSigned(bureaucrat);
    	    form.execute(bureaucrat);
    	    std::cout << "PresidentialPardonForm test passed." << std::endl;
    	} catch (std::exception &e) {
    	    std::cerr << "PresidentialPardonForm test failed: " << e.what() << std::endl;
    	}
DECONSTRUCTING
	}
	{	
TESTING
CONSTRUCTING
			Bureaucrat *bureaucrat = new Bureaucrat("John Doe", 1);
    	    PresidentialPardonForm *form = new PresidentialPardonForm("Target A");

    	try {
    	    bureaucrat->signForm(*form);
    	    bureaucrat->executeForm(*form);
    	    std::cout << "PresidentialPardonForm test passed." << std::endl;
    	} catch (std::exception &e) {
    	    std::cerr << "PresidentialPardonForm test failed: " << e.what() << std::endl;
    	}
DECONSTRUCTING
		delete bureaucrat;
		delete form;
	}
}

void testShrubberyCreationForm() {
TESTING
CONSTRUCTING
        Bureaucrat bureaucrat("Jane Doe", 1);
        ShrubberyCreationForm form("Garden");
    try {
        form.beSigned(bureaucrat);
        form.execute(bureaucrat);
        std::cout << "ShrubberyCreationForm test passed." << std::endl;
    } catch (std::exception &e) {
        std::cerr << "ShrubberyCreationForm test failed: " << e.what() << std::endl;
    }
DECONSTRUCTING
}

void testRobotomyRequestForm() {
TESTING
CONSTRUCTING
        Bureaucrat bureaucrat("Alice", 1);
        RobotomyRequestForm form("Robot");
    try {
        form.beSigned(bureaucrat);
        form.execute(bureaucrat);
        std::cout << "RobotomyRequestForm test passed." << std::endl;
    } catch (std::exception &e) {
        std::cerr << "RobotomyRequestForm test failed: " << e.what() << std::endl;
    }
DECONSTRUCTING
}

void testBureaucrat() {
TESTING
CONSTRUCTING
        Bureaucrat bureaucrat("Bob", 1);
    try {
        std::cout << "Bureaucrat test passed." << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Bureaucrat test failed: " << e.what() << std::endl;
    }
DECONSTRUCTING
}

void tesFormsignAndExecute(){

std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
		JUST_NEW_LINE

		CONSTRUCTING
		Bureaucrat *a = new Bureaucrat("Assistant", 145);
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new PresidentialPardonForm("bsoykan");
		Form *d = new RobotomyRequestForm("bsoykan2");
		Form *e = new ShrubberyCreationForm("bsoykan3");
		
		JUST_NEW_LINE
TESTING
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << e << std::endl;
		JUST_NEW_LINE
TESTING
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "error ->>>>>> " << e.what() << std::endl;
		}
TESTING
		try
		{
			c->execute(*b);
		}
		catch (Form::FormNotSignedException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
JUST_NEW_LINE
TESTING
		try
		{
			c->beSigned(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

JUST_NEW_LINE
		std::cout << c;
JUST_NEW_LINE
TESTING
		try
		{
			c->beSigned(*b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << b->getName() << " was not able to sign the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
JUST_NEW_LINE
		std::cout << c;
JUST_NEW_LINE

JUST_NEW_LINE
		b->signForm(*c);
JUST_NEW_LINE
TESTING
		try
		{
			c->execute(*a);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}
		catch(Form::FormNotSignedException &e)
		{
			std::cerr << "\033[33m" << a->getName() << " was not able to execute the Form " << c->getName() << ": " << e.what() << "\033[0m" << std::endl;
		}

JUST_NEW_LINE

DECONSTRUCTING
		delete a;
		delete b;
		delete c;
		delete d;
		delete e;
JUST_NEW_LINE

}

void testExecuteFormInBureaucrat(){
		Bureaucrat *b = new Bureaucrat("CEO", 1);
		Form *c = new PresidentialPardonForm("bsoykan");
TESTING
		try
		{
			b->signForm(*c);
			b->executeForm(*c);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << "error ->>>>>> " << e.what() << std::endl;
		}
DECONSTRUCTING
		delete b;
		delete c;

}

int main() {
	
	testExecuteFormInBureaucrat();
	//testPresidentialPardonForm();
    //testShrubberyCreationForm();
    //testRobotomyRequestForm();
    //testBureaucrat();
	//tesFormsignAndExecute();

    return 0;
}



	

