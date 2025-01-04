#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

Cat::~Cat(){
    std::cout << "Cat destructor" << std::endl;
    delete(this->_brain);
}

Cat::Cat(const Cat &copy) {
    std::cout << "Cat Copy constructor" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &src){
    std::cout << "Cat Copy assignment operator" << std::endl;
    if (this != &src)
        this->_type = src._type;
    
    this->_brain = new Brain();
    *this->_brain = *src._brain;
    
    return *this;
}


void Cat::getIdea(int i) {
    if (i < 100)
        std::cout << this->_brain->getIdea(i) << std::endl;
}


void Cat::setIdea(int i, std::string _ideas){
    this->_brain->setIdea(i, _ideas);
}


void Cat::makeSound()const{
    std::cout << this->_type << " says MEAWW MEAWWWW" << std::endl;

}