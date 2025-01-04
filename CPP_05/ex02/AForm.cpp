#include "AForm.hpp"


Form::Form() : _name("Default"), _grade(150), _execute_grade(150), _sing(false) {
    std::cout << "Form, Default constructor" << std::endl;
}

Form::Form(int grade) : _name("Default"), _grade(grade), _execute_grade(150), _sing(false) {
    std::cout << "Form, grade constructor" << std::endl;
}
Form::Form(bool sing) : _sing(sing), _grade(150), _execute_grade(150) {
    std::cout << "Form, sing constructor" << std::endl;
}

Form::Form(const std::string name) : _name(name), _grade(150), _execute_grade(150), _sing(false) {
    std::cout << "Form, name constructor" << std::endl;
}

Form::Form(const std::string name, int grade) : _name(name), _grade(grade), _execute_grade(150), _sing(false) {
    std::cout << "Form, name-grade constructor" << std::endl;
            if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        else if (grade < 1)
            throw Bureaucrat::GradeTooLowException();
}

Form::Form(const std::string name, int grade, int execgrade) : _name(name), _grade(grade), _execute_grade(execgrade), _sing(false) {
    std::cout << "Form, name-grade-execgrade constructor" << std::endl;
            if (grade > 150)
            throw Bureaucrat::GradeTooHighException();
        else if (grade < 1)
            throw Bureaucrat::GradeTooLowException();
}

Form::~Form() {
    std::cout << this->getName() << ", Form destructor" << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _grade(copy._grade), _execute_grade(copy._execute_grade), _sing(copy._sing) {
    std::cout << "Form Copy constructor" << std::endl;
    *this = copy;
}

Form &Form::operator=(const Form &src){
    std::cout << "Form Copy assignment operator" << std::endl;

    return *this;
}

const std::string &Form::getName() const {
    return this->_name;
}

int Form::getGrade() const{
    return this->_grade;
}

int Form::getExecute_grade() const{
    return this->_execute_grade;
}

bool Form::getIsSigned(void) const{
    return (this->_sing);
}

void Form::beSigned(Bureaucrat &sign) {
    if (sign.getGrade() >= this->getGrade())
        throw Bureaucrat::GradeTooLowException();
    else if (!(this->getIsSigned())){
        std::cout << sign.getName() << ", signed " << this->getName() << std::endl;
        this->_sing = true;
    }
    else
        std::cout << sign.getName() << ", couldn’t sign " << this->getName() << " because already signed." << std::endl;

}

const char* Form::GradeTooHighException::what(void) const throw() {
    return "grade too high";
}

const char* Form::GradeTooLowException::what(void) const throw() {
    return "grade too low";
}

const char* Form::FormNotSignedException::what() const throw() {
    return "form not signed";
}

std::ostream &operator<<(std::ostream &os, Form *obj){
    return os << " _Form name-> " << obj->getName() << "\n _form_is_sign-> " <<
    obj->getIsSigned() << "\n _execute_grade-> " << 
    obj->getExecute_grade() << "\n _grade-> " << obj->getGrade() << std::endl;
}

