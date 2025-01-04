#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

#define ARRAY_LEN 3
#define ARRAY_LEN2 5
#define JUST_NEW_LINE std::cout << std::endl;
#define CHAR_TEST std::cout << "\033[1;34mchar array test\033[0m" << std::endl;
#define INT_TEST std::cout << "\033[1;34mint array test\033[0m" << std::endl;

template <typename T>
void iter(const T *adress, int len, void (*func)(const T&)) {
    if (adress == NULL)
        return;
    for (int i = 0; i < len; i++)
        func(adress[i]);
}

template <typename T>
void iter(T *adress, int len, void (*func)(T&)) {
    if (adress == NULL)
        return;
    for (int i = 0; i < len; i++)
        func(adress[i]);
}


#endif