#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstddef>
#include <string>
#include <limits>
#include <limits.h>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#define INPUT std::string &input
#define ISFIND std::string::npos
#define CONVERT_INPUTS std::string input, char &_char, int &_int, float &_float, double &_double
#define SCALARVALUES ScalarValues &a

#define IHATEMAC 0.0
#define IHATEMAC2 0
#define IHATEMAC3 '\0'

enum ValueType {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    FLOATING_EXCEPTIONS,
    PROBLEM
};

struct ScalarValues {
    char _char;
    int _int;
    float _float;
    double _double;
    enum ValueType typeR;
};

class ScalarConverter {

    public:
        ~ScalarConverter();
        ScalarConverter(const std::string input_val);
        static void convert(std::string input);

    private:
        double _double;
        std::string _value;
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);

        ScalarConverter &operator=(const ScalarConverter &src);
        static ScalarValues convert_value(INPUT);
        static ValueType checkValType(INPUT);
        static void printValues(INPUT, ScalarValues &a);
        static void charDisplay(ScalarValues &a);
        static void intDisplay(ScalarValues &a);
        static bool isWithinIntRange(double value);
        static void floatDisplay(INPUT, ScalarValues &a);
        static void doubleDisplay(INPUT, ScalarValues &a);
        static ScalarValues variables(char _char, int _int, float _float, double _double, ValueType typeR);
        static void fromChar(CONVERT_INPUTS);
        static void fromInt(CONVERT_INPUTS);
        static void fromFloat(CONVERT_INPUTS);
        static void fromDouble(CONVERT_INPUTS);
        static bool checkFloatingExceptions(INPUT);
        static bool isChar(INPUT);
        static bool doubleSign(INPUT);
        static bool isInt(INPUT);
        static bool isDoubleDot(INPUT);
        static bool isFirstDigitDot(INPUT);
        static bool isFloat(INPUT);
        static bool isDoubleF(INPUT);
        static bool isAloneF(INPUT);
        static bool isAnyAfterF(INPUT);
        static void ifProblem(ScalarValues &a);
        static bool invalidSignPosition(INPUT);
};

#endif

