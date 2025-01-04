#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

Base::~Base(){}

Base *generate(void) {
    std::srand(std::time(0));
    int randomVal = std::rand() % 3;

    switch (randomVal) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }   
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "p is: A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p)) {
        std::cout << "p is: B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "p is: C" << std::endl;
    }
    else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "p is: A" << std::endl;
    } catch (std::exception &bc) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "p is: B" << std::endl;
        } catch (std::exception &bc) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "p is: C" << std::endl;
            } catch (std::exception &bc) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}
