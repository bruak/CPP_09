#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main() {

{
CONSTRUCTING
    Bureaucrat *bureaucrat = new Bureaucrat(140);
JUST_NEW_LINE

TESTING
    try {
        for (int i = 0; i < 11; i++) {
            bureaucrat->decrement_grade();
        }
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << bureaucrat->getName() << "\033[33m Grade too high exaption-> \033[0m" << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << bureaucrat->getName() << "\033[33m Grade too low exaption-> \033[0m" << e.what() << std::endl;
    }

    std::cout << bureaucrat << std::endl;
    delete bureaucrat;
}    

{

CONSTRUCTING
    Bureaucrat *bureaucrat = new Bureaucrat(5);
JUST_NEW_LINE

TESTING
    try {
        for (int i = 0; i < 10; i++){
            bureaucrat->increment_grade();
        }
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cerr << bureaucrat->getName() << "\033[33m Grade too high exaption-> \033[0m" << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cerr << bureaucrat->getName() << "\033[33m Grade too low exaption-> \033[0m" << e.what() << std::endl;
    }

    std::cout << bureaucrat << std::endl;

JUST_NEW_LINE
DECONSTRUCTING
    return delete bureaucrat, 0;
}



}
