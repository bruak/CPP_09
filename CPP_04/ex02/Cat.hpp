#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

    public:
        Cat();
        Cat( const Cat &copy);
        ~Cat();

        Cat &operator=(const Cat &src);

        void getIdea(int i);
        void setIdea(int i, std::string _ideas);
        
        void makeSound()const;

    private:
        Brain *_brain;

};


#endif