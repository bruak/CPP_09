#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("default") {
    std::cout << "PresidentialPardonForm, Default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : Form("PresidentialPardonForm", 25, 5), _target(name) {
    std::cout << "PresidentialPardonForm, Default constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << this->getName() << ", PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form("PresidentialPardonForm", 25, 5), _target(src._target) {
    std::cout << "PresidentialPardonForm copy Constructor" << std::endl;
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
    std::cout << "PresidentialPardonForm Copy assignment operator" << std::endl;
    return *this;
}

const std::string PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {

    if (executor.getGrade() >= this->getExecute_grade())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getIsSigned() == false)
        std::cout << "form not signed yet!" << std::endl;
    else
        std::cout << executor.getName() << ", executed " << this->getName() << std::endl;
}

std::ostream &operator<<(std::ostream &os, PresidentialPardonForm *obj){
    return os << " _PresidentialPardonForm name-> " << obj->getName() << "\n _form_is_sign-> " <<
    obj->getIsSigned() << "\n _execute_grade-> " << 
    obj->getExecute_grade() << "\n _grade-> " << obj->getGrade() << std::endl;
}
