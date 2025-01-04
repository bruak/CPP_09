#include "Fixed.hpp"

Fixed::Fixed() : FixedPointNumber(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &otherFixedClass ){
    std::cout << "Copy constructor called" << std::endl;
    *this = otherFixedClass;
}

Fixed &Fixed::operator=( const Fixed &otherFixedClass ){

    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &otherFixedClass)
        this->FixedPointNumber = otherFixedClass.getRawBits();
    else 
        std::cout << "You can't copy the same object" << std::endl;
    return *this;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->FixedPointNumber;
}

void Fixed::setRawBits( int const raw ){
    this->FixedPointNumber = raw;
}

