#include "Dog.hpp"
#include "Brain.hpp"


Dog::Dog(){
    std::cout << "Dog Default constructor" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::~Dog(){
    std::cout << "Dog destructor" << std::endl;
    delete this->_brain;
}

Dog::Dog(const Dog &copy) {
    std::cout << "Dog Copy constructor" << std::endl;
    *this = copy;
    
}

Dog &Dog::operator=(const Dog &src){
    std::cout << "Dog Copy assignment operator" << std::endl;
    if (this != &src)
        this->_type = src._type;
    
    this->_brain = new Brain(*src._brain);
    
    return *this;
}

void Dog::getIdea(int i) {
    if (i < 100)
        std::cout << this->_brain->getIdea(i) << std::endl;
}


void Dog::setIdea(int i, std::string _ideas){
    this->_brain->setIdea(i, _ideas);
}

void Dog::makeSound()const{
    std::cout << this->_type << " says HOAW HOAW HOAW" << std::endl;
}
