#include <iostream>

class Fixed {
    private:
    int FixedPointNumber;
    static const int fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed( int const &intParamater );
        Fixed( float const &floatPointMember );
        Fixed( const Fixed &otherFixedClass );
    
        Fixed &operator=( const Fixed &otherFixedClass );
    
        int getRawBits( void ) const;
        void setRawBits( int const raw );

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<( std::ostream &os, const Fixed &fp);

    