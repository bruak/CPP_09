#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        Form();
        Form(int grade);
        Form(bool sing);
        Form(const std::string name);
        Form(const std::string name, int grade);
        Form(const Form &copy);
        ~Form();

        Form& operator=(const Form &src);

        const std::string getName();
        void beSigned(Bureaucrat &sign);

        int getIsSigned();
        int getGrade();
        int getExecute_grade();

        class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };

    private:
        const std::string _name;
        bool  _sing;
        const int _grade;
        const int _execute_grade;

};

std::ostream &operator<<(std::ostream &os, Form *obj);

#endif