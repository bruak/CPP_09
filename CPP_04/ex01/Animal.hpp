#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {

    public:
        Animal();
        Animal( const Animal &copy);
        virtual ~Animal();

        Animal &operator=(const Animal &src);

        std::string get_type() const;

        virtual void makeSound() const;
    
    protected:
        std::string _type;
};

#endif
