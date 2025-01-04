#include "ScalarConverter.hpp"


void ScalarConverter::printValues(INPUT, SCALARVALUES) {
    ifProblem(a);
    charDisplay(a);
    intDisplay(a);
    floatDisplay(input, a);
    doubleDisplay(input, a);
}

void ScalarConverter::ifProblem(SCALARVALUES) {
    if (a.typeR == PROBLEM) {
            std::cout << "char: Impossible" << std::endl;
            std::cout << "int: Impossible" << std::endl;
            std::cout << "float: Impossible" << std::endl;
            std::cout << "double: Impossible" << std::endl;
            exit(1);
        }
}

void ScalarConverter::charDisplay(SCALARVALUES) {
    if (a.typeR != FLOATING_EXCEPTIONS && a._double <= CHAR_MAX && a._double >= 0)
        if (isprint(a._char))
            std::cout << "char: '" << a._char << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    else
            std::cout << "char: Impossible" << std::endl;
}

void ScalarConverter::intDisplay(SCALARVALUES) {
    if (a.typeR != FLOATING_EXCEPTIONS && isWithinIntRange(a._double)) {
            std::cout << "int: " << a._int << std::endl;
    }
    else
            std::cout << "int: Impossible" << std::endl;
}

bool ScalarConverter::isWithinIntRange(double value) {
    return value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

void ScalarConverter::floatDisplay(INPUT, SCALARVALUES) {
    if (a.typeR != FLOATING_EXCEPTIONS) 
        std::cout << "float: " << std::fixed << std::setprecision(1) << a._float << "f" << std::endl;
    else {
        if (input == "-inff")
            std::cout << "float: -inff" << std::endl;
        else if (input == "+inff")
            std::cout << "float: +inff" << std::endl;
        else if (input == "+inf")
            std::cout << "float: +inff" << std::endl;
        else if (input == "nan")
            std::cout << "float: nanf" << std::endl;
        else if (input == "-inf")
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: -nanf" << std::endl;
    }
}

void ScalarConverter::doubleDisplay(INPUT, SCALARVALUES) {
    if (a.typeR != FLOATING_EXCEPTIONS)
        std::cout << "double: " << a._double << std::endl;
    else {
        if (input == "nan")
            std::cout << "double: nan" << std::endl;
        else if (input == "-inff")
            std::cout << "double: -inf" << std::endl;
        else if (input == "+inff")
            std::cout << "double: +inf" << std::endl;
        else if (input == "+inf")
            std::cout << "double: +inf" << std::endl;
         else if (input == "-inf")
            std::cout << "double: -inf" << std::endl;
        else if (input[0] == '+')
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
}
