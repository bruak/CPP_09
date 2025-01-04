#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : Form("RobotomyRequestForm", 72, 45), _target(name) {
    std::cout << "RobotomyRequestForm, Default constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << this->getName() << ", RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form("RobotomyRequestForm", 72, 45), _target(src._target) {
    std::cout << "RobotomyRequestForm copy Constructor" << std::endl;
    *this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
    std::cout << "RobotomyRequestForm Copy assignment operator" << std::endl;
    return *this;
}

const std::string RobotomyRequestForm::getTarget() const {
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

    if (executor.getGrade() >= this->getExecute_grade())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getIsSigned() == false)
        std::cout << "form not signed yet!" << std::endl;
    else if (std::rand() % 2 == 0)
        std::cout << "BZBZBZBZBZ\n " << this->getTarget() << ", has been robotomized by " << this->getName() << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;

}

std::ostream &operator<<(std::ostream &os, RobotomyRequestForm *obj){
    return os << " _RobotomyRequestForm name-> " << obj->getName() << "\n _form_is_sign-> " <<
    obj->getIsSigned() << "\n _execute_grade-> " << 
    obj->getExecute_grade() << "\n _grade-> " << obj->getGrade() << std::endl;
}
