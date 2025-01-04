#include "Fixed.hpp"
#include <cmath>

#define FIXED_POINT_SCALE_FACTOR 256

Fixed::Fixed() : FixedPointNumber(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int &intParamater ) {
    std::cout << "Int constructor called" << std::endl;
    this->FixedPointNumber = intParamater * FIXED_POINT_SCALE_FACTOR;
}

Fixed::Fixed( const float &floatPointMember ) {
    std::cout << "Float constructor called" << std::endl;
    this->FixedPointNumber = roundf(floatPointMember * FIXED_POINT_SCALE_FACTOR);
}

float Fixed::toFloat( void ) const {
    float number = (float)FixedPointNumber / FIXED_POINT_SCALE_FACTOR; 
    return number;
}

int Fixed::toInt( void ) const {
    return (int)FixedPointNumber / FIXED_POINT_SCALE_FACTOR;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &otherFixedClass ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = otherFixedClass;
}

Fixed &Fixed::operator=( const Fixed &otherFixedClass ) {
    
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &otherFixedClass)
        this->FixedPointNumber = otherFixedClass.getRawBits();
    else 
        std::cout << "You can't copy the same object" << std::endl;
    return *this;
}

int Fixed::getRawBits( void ) const {
    return this->FixedPointNumber;
}

void Fixed::setRawBits( int const raw ) {
    this->FixedPointNumber = raw;
}

std::ostream &operator<<( std::ostream &os, Fixed const &fp){
    return os << fp.toFloat();
}
