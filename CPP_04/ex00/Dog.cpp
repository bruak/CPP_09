#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog Default constructor" << std::endl;
    this->_type = "Dog";
}

Dog::~Dog(){
    std::cout << "Dog destructor" << std::endl;

}

Dog::Dog(const Dog &copy) {
    std::cout << "Dog Copy constructor" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &src){
    std::cout << "Dog Copy assignment operator" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

void Dog::makeSound()const{
    std::cout << this->_type << "says HOAW HOAW HOAW" << std::endl;
}
