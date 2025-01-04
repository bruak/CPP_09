#include "Fixed.hpp"
#include <cmath>

#define FIXED_POINT_SCALE_FACTOR 256

Fixed::Fixed() : FixedPointNumber(0) {
}

Fixed::~Fixed() {
}

Fixed::Fixed( const int &intParamater ) {
    this->FixedPointNumber = intParamater << fractionalBits;
}

Fixed::Fixed( const float &floatPointMember ) {
    this->FixedPointNumber = roundf(floatPointMember * FIXED_POINT_SCALE_FACTOR);
}

float Fixed::toFloat( void ) const {
    
    float number = (float)FixedPointNumber / FIXED_POINT_SCALE_FACTOR; 
    return number;
}

int Fixed::toInt( void ) const {
    return FixedPointNumber >> fractionalBits;
}

Fixed::Fixed( const Fixed &otherFixedClass ) {
    *this = otherFixedClass;
}

Fixed &Fixed::operator=( const Fixed &otherFixedClass ) {
    
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

bool Fixed::operator>( const Fixed &otherFixedClass) const {
	return (this->toFloat() > otherFixedClass.toFloat());
}

bool Fixed::operator<( const Fixed &otherFixedClass) const {
    return (this->toFloat() < otherFixedClass.toFloat());
}

bool Fixed::operator>=( const Fixed &otherFixedClass) const {
    return (this->toFloat() >= otherFixedClass.toFloat());
}

bool Fixed::operator<=( const Fixed &otherFixedClass) const {
    return (this->toFloat() <= otherFixedClass.toFloat());
}

bool Fixed::operator==( const Fixed &otherFixedClass) const {
    return (this->toFloat() == otherFixedClass.toFloat());
}

bool Fixed::operator!=( const Fixed &otherFixedClass) const {
    return (this->toFloat() != otherFixedClass.toFloat());
}

float Fixed::operator+( const Fixed &otherFixedClass) const {
    return (this->toFloat() + otherFixedClass.toFloat());
}

float Fixed::operator-( const Fixed &otherFixedClass) const {
    return (this->toFloat() - otherFixedClass.toFloat());
}

float Fixed::operator*( const Fixed &otherFixedClass) const {
    return (this->toFloat() * otherFixedClass.toFloat());
}

float Fixed::operator/( const Fixed &otherFixedClass) const {
    return (this->toFloat() / otherFixedClass.toFloat());
}

Fixed	Fixed::operator++(void) {
	this->FixedPointNumber++;
	return (*this);
}

Fixed	Fixed::operator--(void) {
	this->FixedPointNumber--;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp = *this;
	this->FixedPointNumber++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp = *this;
	this->FixedPointNumber--;
	return (tmp);
}

Fixed& Fixed::min(Fixed &first, Fixed &second) {
    if (first.toFloat() <= second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
    if (first.toFloat() <= second.toFloat())
        return (first);
    else
        return (second);
}

Fixed& Fixed::max(Fixed &first, Fixed &second) {
    if (first.toFloat() >= second.toFloat())
        return (first);
    else
        return (second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
    if (first.toFloat() >= second.toFloat())
        return (first);
    else
        return (second);
}
