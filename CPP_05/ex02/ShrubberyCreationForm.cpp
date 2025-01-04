#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : Form("ShrubberyCreationForm", 145, 137), _target(name) {
    std::cout << "ShrubberyCreationForm, Default constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << this->getName() << ", ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form("ShrubberyCreationForm", 145, 137), _target(src._target) {
    std::cout << "ShrubberyCreationForm copy Constructor" << std::endl;
    *this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
    std::cout << "ShrubberyCreationForm Copy assignment operator" << std::endl;
    return *this;
}

const std::string ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {

    if (executor.getGrade() >= this->getExecute_grade())
        throw Bureaucrat::GradeTooLowException();
    else if (this->getIsSigned() == false)
        throw Form::FormNotSignedException();
    else
        {
            std::ofstream file;
            std::string fileName = this->getTarget() + ("_shrubbery");
            file.open(fileName);

            if (file.is_open()){
                file << ASCII_TREE;
                file.close();
            }
            else{
                std::cerr << "file open err" << std::endl;
            }
        }
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm *obj){
    return os << " _RobotomyRequestForm name-> " << obj->getName() << "\n _form_is_sign-> " <<
    obj->getIsSigned() << "\n _execute_grade-> " << 
    obj->getExecute_grade() << "\n _grade-> " << obj->getGrade() << std::endl;
}
