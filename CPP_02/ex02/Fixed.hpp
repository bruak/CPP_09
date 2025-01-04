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
        
        float toFloat( void ) const;
        int toInt( void ) const;    

        int getRawBits( void ) const;
        void setRawBits( int const raw );   

        bool operator>( const Fixed &otherFixedClass ) const;
        bool operator<( const Fixed &otherFixedClass ) const;
        bool operator>=( const Fixed &otherFixedClass ) const;
        bool operator<=( const Fixed &otherFixedClass ) const;
        bool operator==( const Fixed &otherFixedClass ) const;
        bool operator!=( const Fixed &otherFixedClass ) const;

        float operator+( const Fixed &otherFixedClass ) const;
        float operator-( const Fixed &otherFixedClass ) const;
        float operator*( const Fixed &otherFixedClass ) const;
        float operator/( const Fixed &otherFixedClass ) const;
        
        Fixed operator++(void);
        Fixed operator--(void);

        Fixed operator++(int);
        Fixed operator--(int);


        static Fixed &min( Fixed &fixedPoint1, Fixed &fixedPoint2 );
        static const Fixed &min( Fixed const &fixedPoint1, Fixed const &fixedPoint2 );

        static Fixed &max( Fixed &fixedPoint1, Fixed &fixedPoint2 );
        static const Fixed &max( Fixed const &fixedPoint1, Fixed const &fixedPoint2 );

};

std::ostream &operator<<( std::ostream &os, const Fixed &fp);

