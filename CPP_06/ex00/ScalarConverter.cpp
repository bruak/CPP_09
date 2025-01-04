#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const std::string input_val) : _value(input_val) {
    convert(_value);
}

void ScalarConverter::convert(std::string input) {
    ScalarValues a = convert_value(input);
    printValues(input, a);
}

ScalarValues ScalarConverter::convert_value(INPUT) {
    char _char = IHATEMAC3;
    int _int = IHATEMAC2;
    float _float = IHATEMAC;
    double _double = IHATEMAC;
    ScalarValues a;

    ValueType witch_val = checkValType(input);

    if (witch_val == FLOATING_EXCEPTIONS)    
        return a = variables(_char, _int, _float, _double, witch_val); 

    switch (witch_val) {
    case CHAR:
        fromChar(input, _char, _int, _float, _double);
        break;
    case INT:
        fromInt(input, _char, _int, _float, _double);
        break;
    case FLOAT:
        fromFloat(input, _char, _int, _float, _double);
        break;
    case DOUBLE:
        fromDouble(input, _char, _int, _float, _double);
        break;
    default:
        break;
    }

    a = variables(_char, _int, _float, _double, witch_val);
    return (a);
}

ScalarValues ScalarConverter::variables(char _char, int _int, float _float, double _double, ValueType typeR) {
    ScalarValues a;
    a._char = _char;
    a._int = _int;
    a._float = _float;
    a._double = _double;
    a.typeR = typeR;
    return a;
}

void ScalarConverter::fromChar(CONVERT_INPUTS) {
    
    _char = static_cast<char>(input[0]);
    _int = static_cast<int>(_char);
    _float = static_cast<float>(_char);
    _double = static_cast<double>(_char);
}

void ScalarConverter::fromInt(CONVERT_INPUTS) {
    double _double_for_cast = atof(input.c_str());
    
    _int = static_cast<int>(_double_for_cast);
    _char = static_cast<char>(_int);
    _float = static_cast<float>(_double_for_cast);

    _double = _double_for_cast;
}

void ScalarConverter::fromFloat(CONVERT_INPUTS) {
    double _double_for_cast = atof(input.c_str());

    _float = static_cast<float>(_double_for_cast);
    _char = static_cast<char>(_float);
    _int = static_cast<int>(_float);

    _double = _double_for_cast;
}

void ScalarConverter::fromDouble(CONVERT_INPUTS) {
    double _double_for_cast = atof(input.c_str());

    _char = static_cast<char>(_double_for_cast);
    _int = static_cast<int>(_double_for_cast);
    _float = static_cast<float>(_double_for_cast);

    _double = _double_for_cast;
}
