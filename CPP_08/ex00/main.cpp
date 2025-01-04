#include "whatever.hpp"

int main() {
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
JUST_NEW_LINE
    ::swap( a, b );
    std::cout << "swaped a, b" << std::endl;
JUST_NEW_LINE
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
JUST_NEW_LINE
    std::cout << "min( a, b ) = " << ::min( b, a ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( b, a ) << std::endl;

JUST_NEW_LINE
    std::string c = "crook1";
    std::string d = "crook2";
JUST_NEW_LINE
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
JUST_NEW_LINE
    ::swap(c, d);
    std::cout << "swaped c, d" << std::endl;
JUST_NEW_LINE
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
JUST_NEW_LINE
/*
* lexicographical order
*/
    std::cout << "min( c, d ) = " << ::min( d, c ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( d, c ) << std::endl;

    return 0;
}