#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "WrongCat Default constructor" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor" << std::endl;

}

WrongCat::WrongCat(const WrongCat &copy) {
    std::cout << "WrongCat Copy constructor" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
    std::cout << "WrongCat Copy assignment operator" << std::endl;
    this->_type = src._type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << this->_type << "says MEAWW MEAWWWW" << std::endl;

}