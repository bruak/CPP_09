#include "ScalarConverter.hpp"

ValueType ScalarConverter::checkValType(INPUT) {
    if (checkFloatingExceptions(input))
        return FLOATING_EXCEPTIONS;
    else if (isChar(input))
        return CHAR;
    else if (doubleSign(input))
        return PROBLEM;
    else if (invalidSignPosition(input))
        return PROBLEM;
    else if (isInt(input))
        return INT;
    else if (isFloat(input))
        return FLOAT;
    else
        return PROBLEM;
}

bool ScalarConverter::checkFloatingExceptions(INPUT) {
    if (input.compare("nan") == 0 || input.compare("+inf") == 0 ||
        input.compare("-inf") == 0 || input.compare("+inff") == 0 ||
        input.compare("-inff") == 0)
        return true;
    else
        return false;
}

bool ScalarConverter::isChar(INPUT) {
    if (input.length() == 1 && !std::isdigit(input[0]) &&
        std::isprint(input[0]) && std::isalpha(input[0]))
        return true;
    return false;
}

/*
 * double +- op check.
 */
bool ScalarConverter::doubleSign(INPUT) {
    if (input.find_first_of("+-") != input.find_last_of("+-"))
        return true;
    return false;
}

bool ScalarConverter::invalidSignPosition(INPUT) {
    if (input == "-" || 
        input.find_first_of("+-") != input.find_last_of("+-") || 
        (input.find_first_of("+-") > input.find('.')) || 
        (input.find_first_of("+-") > 0 && input.find_first_of("+-") != ISFIND)) 
        return true;
    return false;
}

/*
 * find err if find without sign and number.
 */
bool ScalarConverter::isInt(INPUT) {
    if (input.find_first_not_of("+-0123456789") == ISFIND)
        return true;
    return false;
}

bool ScalarConverter::isDoubleDot(INPUT) {
    if (input.find_first_of(".") != input.find_last_of("."))
        return true;
    return false;
}

/*
 * find function will return pos the target at index
 */
bool ScalarConverter::isFirstDigitDot(INPUT) {
    if (input.find_first_of(".") == 0)
        return true;
    return false;
}

bool ScalarConverter::isFloat(INPUT) {
    if (input.find_first_not_of("+-0123456789.f") == ISFIND && !(isDoubleF(input) ||
            isDoubleDot(input) || isAloneF(input) || isFirstDigitDot(input) || isAnyAfterF(input)))
        return true;
    return false;
}

bool ScalarConverter::isDoubleF(INPUT) {
    if (input.find_first_of("f") != input.find_last_of("f"))
        return true;
    return false;
}

/*
 * its for 0.f calculated like this -> f = 2.index, "." = 1.index 2-1 = 1.
 */
bool ScalarConverter::isAloneF(INPUT) {
    if (input.find_first_of("f") - input.find_first_of(".") == 1)
        return true;
    return false;
}

bool ScalarConverter::isAnyAfterF(INPUT) {
    size_t fPos = input.find("f");

    if (fPos != ISFIND && 'f' == input.length() - 1)
        return true;
    return false;
}
