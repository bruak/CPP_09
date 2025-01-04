#include "Fixed.hpp"
#include <iostream>

int main( void ) {

    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
        std::cout << Fixed::min( a, b) << std::endl;
    }

    {
        std::cout << "******these my own tests******" << std::endl;
        Fixed a (10);
        Fixed b (15);
        std::cout << "*****boolen operators******" << std::endl;
        (a > b) ? std::cout << "a bigger" << std::endl : std::cout << "b bigger" << std::endl;
        (a < b) ? std::cout << "a smaller" << std::endl : std::cout << "b smaller" << std::endl;
        std::cout << "a.setRawBits(15), setted" << std::endl;
        a.setRawBits(b.getRawBits());
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        (a >= b) ? std::cout << "a is bigger or equvailent" << std::endl : std::cout << "b is smaller or equvailent" << std::endl;
        (a <= b) ? std::cout << "a is smaller or equvailent" << std::endl : std::cout << "b is bigger or equvailent" << std::endl;
        (a == b) ? std::cout << "a equvailent to b" << std::endl : std::cout << "a equvailent to b" << std::endl;
        (a != b) ? std::cout << "a not equvailent to b" << std::endl : std::cout << "a equvailent to b" << std::endl;
        std::cout << "*****4 transactions with float*****" << std::endl;
        std::cout << "a + b operator test = " << a + b << std::endl;
        std::cout << "a - b operator test = " << a - b << std::endl;
        std::cout << "a * b operator test = " << a * b << std::endl;
        std::cout << "a / b operator test = " << a / b << std::endl;
        std::cout << "******min max const normal tests******" << std::endl;
        std::cout << "a.setRawBits(1), b.setRawbits(2), setted" << std::endl;
        a.setRawBits(256);
        b.setRawBits(512);
        std::cout << Fixed::max(a, b) << std::endl;
        std::cout << Fixed::min(a, b) << std::endl;
        std::cout << "a object casted const to new value 'constA'" << std::endl;
        const Fixed& constA = const_cast<const Fixed&>(a);

        std::cout << "const 'max' function was executed -> " << Fixed::max(constA, b) << std::endl;
        std::cout << "const 'min' function was executed -> " << Fixed::min(constA, b) << std::endl;
        std::cout << "************test finished***********" << std::endl;
    }
    return 0;
}