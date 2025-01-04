#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain Copy constructor" << std::endl;

    *this = copy;
}

Brain::~Brain() {
    std::cout << "Brain destructor" << std::endl;

}

Brain& Brain::operator=(const Brain &src) {
    std::cout << "Brain Copy assignment operator" << std::endl;

    for (int i = 0; i < 100; i++)
            this->_ideas[i].assign(src._ideas[i]);

    return *this;
}

const std::string Brain::getIdea(int i) const {
    if (i < 100)
        return (this->_ideas[i]);
    return ("\033[33mThere is only 100 ideas per brain.\033[0m");
}

void Brain::setIdea(int N, std::string _ideas) {
    if (N < 100)
        this->_ideas[N] = _ideas;
    else
        std::cout << "\033[33mThere is only 100 ideas per brain.\033[0m" << std::endl;
    
}
