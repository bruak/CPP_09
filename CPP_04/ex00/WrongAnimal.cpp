#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal Default constructor" << std::endl;
    this->_type = "default";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor" << std::endl;

}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    std::cout << "WrongAnimal Copy constructor" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src){
    std::cout << "WrongAnimal Copy assignment operator" << std::endl;
    this->_type = src._type;
    return *this;
}

void WrongAnimal::makeSound()const {
    std::cout << "this is a WrongAnimal Class makesound function" << std::endl;
}


std::string WrongAnimal::get_type() const{
    return (this->_type);
}