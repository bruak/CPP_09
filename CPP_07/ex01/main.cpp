#include "iter.hpp"

template <typename T>
void print(T &array) {
    std::cout << array << std::endl;
}

int main() {
CHAR_TEST

    char arr[] = {'X', 'Y', 'Z'};
    iter(arr, ARRAY_LEN, print);

JUST_NEW_LINE
INT_TEST

    int tab[] = {0, 1, 2, 3, 4};
    iter(tab, ARRAY_LEN2, print);
    
}
