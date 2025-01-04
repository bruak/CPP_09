#ifndef ARRAY_TPP
#define ARRAY_TPP

TEPMLATE
Array<T>::Array() : _size(0) {
    std::cout << "Constructor, created array(empty) size of 0" << std::endl;
    _array = NULL;
}

TEPMLATE
Array<T>::Array(unsigned int n) : _size(n) {
    std::cout << "Constructor, created array sizeof(" << n  << ")" << std::endl;
    _array = NULL;
    if (_size)
        _array = new T[_size];
}

TEPMLATE
Array<T>::~Array() {
    std::cout << "Destructor" << std::endl;
    delete[] _array;
}

    TEPMLATE
    Array<T>::Array(const Array &src) : _size(src._size) {
        std::cout << "Copy constructor" << std::endl;
        _array = NULL;
        *this = src;
    }

    TEPMLATE
    Array<T> &Array<T>::operator=(const Array &src)
    {
        std::cout << "Copy assigment" << std::endl;
        if (this->_array != NULL)
        {
            delete [] this->_array;
            _array = NULL;
        }
        if (src.Size() != 0)
        {
            this->_size = src._size;
            this->_array = new T[this->_size];

            for (int i = 0; i < this->Size(); i++)
                this->_array[i] = src._array[i];
        }
        return (*this);
    }

TEPMLATE
T &Array<T>::operator[](unsigned int loc){
    if (loc >= _size || _array == NULL)
        std::cout << "index location: " << loc << std::endl, throw Array<T>::IndexException();
    return (_array[loc]);
}

TEPMLATE
const char *Array<T>::IndexException::what() const throw(){
    return ("Index is out of bounds!");
}

TEPMLATE
int Array<T>::Size() const {
    return (_size);
}

#endif
