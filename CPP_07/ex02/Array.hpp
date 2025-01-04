#ifndef ARRAY_HPP
#define ARRAY_HPP

#define TEPMLATE template <typename T>
#define JUST_NEW_LINE std::cout << std::endl;

#include <iostream>
#include <exception>

TEPMLATE
class Array {

    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int);
        Array(const Array &src);
        Array &operator=(const Array &src);
        ~Array();

        T &operator[](unsigned int loc);

        class IndexException : public std::exception {
            public:
                const char *what() const throw();
        };

        int Size() const;
};

#include "Array.tpp"

#endif