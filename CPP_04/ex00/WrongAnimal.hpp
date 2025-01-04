#ifndef WrongAnimal_CPP
#define WrongAnimal_CPP


#include <iostream>

class WrongAnimal {

    public:
        WrongAnimal();
        WrongAnimal( const WrongAnimal &copy);
        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &src);

        std::string get_type() const ;

        void makeSound() const;
    protected:
        std::string _type;
};

#endif