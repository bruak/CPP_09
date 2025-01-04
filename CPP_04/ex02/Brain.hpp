#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

    public:
        Brain();
        Brain(const Brain &copy);
        virtual ~Brain();

        Brain &operator=(const Brain &src);


        const std::string getIdea(int i) const;

        void setIdea(int i, std::string _ideas);
        
    private:
        std::string _ideas[100];

};



#endif