#include "Base.hpp"

int main() {
    Base *base = generate();

    if (base == NULL) 
        return std::cout << "Base function returned NULL, how :D" << std::endl, 1;

    Base &ref = *base;

    std::cout << base << std::endl;
    identify(base);
    std::cout << &ref << std::endl;
    identify(*base);

    delete base;
}