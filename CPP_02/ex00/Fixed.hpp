#include <iostream>

class Fixed {
    private:
    int FixedPointNumber;
    static const int fractionalBits = 8;

    public:
        Fixed();
        Fixed( const Fixed &otherFixedClass );
        ~Fixed();

        Fixed &operator=( const Fixed &otherFixedClass );

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
