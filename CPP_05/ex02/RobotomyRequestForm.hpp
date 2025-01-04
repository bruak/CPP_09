#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Form;

class RobotomyRequestForm : public Form {

    public: 
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

        const std::string getTarget() const;

        void execute(Bureaucrat const & executor) const;

    private:
        RobotomyRequestForm();
        const std::string _target;
};

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm *obj);

#endif