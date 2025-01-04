#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

#define TESTING std::cout << "\033[34mTesting\033[0m" << std::endl;
#define CONSTRUCTING std::cout << "\033[34mConstructing\033[0m" << std::endl;
#define JUST_NEW_LINE std::cout << std::endl;
#define DECONSTRUCTING std::cout << "\033[34mDeconstructing\033[0m" << std::endl;

class Form;

class Bureaucrat {

    public:
        Bureaucrat();
        Bureaucrat(const std::string name);
        Bureaucrat(int grade);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &src);

        std::string getName() const;
        int getGrade() const;

        void increment_grade();
        void decrement_grade();
        void signForm(Form &Form);
        void executeForm(Form const & Form);
        
        class GradeTooHighException : public std::exception {
            public:
                const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what(void) const throw();
        };

    private:
        const std::string _name;
        unsigned int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat *Bureaucrat_obj);

#endif
