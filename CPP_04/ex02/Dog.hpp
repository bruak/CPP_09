#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {

    public:
        Dog();
        Dog(const Dog &copy);
        ~Dog();

        Dog &operator=(const Dog &src);
        
        void getIdea(int i);
        void setIdea(int i, std::string _ideas);

        void makeSound()const;
    private:
        Brain *_brain;

    
};

#endif