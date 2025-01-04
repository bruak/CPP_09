#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat Default constructor" << std::endl;
    this->_type = "Cat";
}

Cat::~Cat(){
    std::cout << "Cat destructor" << std::endl;

}

Cat::Cat(const Cat &copy) {
    std::cout << "Cat Copy constructor" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &src){
    std::cout << "Cat Copy assignment operator" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

void Cat::makeSound()const{
    std::cout << this->_type << "says MEAWW MEAWWWW" << std::endl;

}