#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Form;
class Bureaucrat;

class PresidentialPardonForm  : public Form {

    public: 
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
        
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

        const std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;

    private:
        PresidentialPardonForm();
        const std::string _target;

};

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm *p);

#endif