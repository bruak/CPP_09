#include "Serializer.hpp"


int main() {
    Data data;
    Data *ptr = &data;
    
    Data *NewPtr;
    
    uintptr_t rawAdress;

    ptr->car = "i20N";


JUST_NEW_LINE
    std::cout << "\033[1;33mAddress of ptr->car: \033[0m" << ptr << std::endl;
    std::cout << "\033[1;33mValue of ptr->car: \033[0m" << ptr->car << std::endl;

    rawAdress = Serializer::serialize(ptr);
    NewPtr = Serializer::deserialize(rawAdress); 

JUST_NEW_LINE
    std::cout << "\033[1;35mraw adress value: \033[0m" << rawAdress << std::endl;

JUST_NEW_LINE
    std::cout << "\033[1;34mAddress of NewPtr->car: \033[0m" << NewPtr << std::endl;
    std::cout << "\033[1;34mValue of NewPtr->car: \033[0m" << NewPtr->car << std::endl;

return 0;

}