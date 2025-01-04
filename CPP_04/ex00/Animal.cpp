#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal Default constructor" << std::endl;
    this->_type = "default";
}

Animal::~Animal(){
    std::cout << "Animal destructor" << std::endl;

}

Animal::Animal(const Animal &copy) {
    std::cout << "Animal Copy constructor" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &src){
    std::cout << "Animal Copy assignment operator" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

void Animal::makeSound()const {
    std::cout << "this is a Animall Class makesound function" << std::endl;
}


std::string Animal::get_type() const{
    return (this->_type);
}