#ifndef Form_HPP
#define Form_HPP

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
        Form(const std::string name, int grade, int execgrade);
        Form(const Form &copy);
        virtual ~Form();

        Form& operator=(const Form &src);

        void beSigned(Bureaucrat &sign);
        virtual void execute(Bureaucrat const & executor) const = 0;

        bool getIsSigned() const;
        int getGrade() const;
        int getExecute_grade() const; 
        const std::string &getName() const;

        class GradeTooHighException : public std::exception {
            public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
            const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
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