#include "ScalarConverter.hpp"
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>

void ScalarConverter::convert(const std::string& literal) {
    double value;
    bool isValidNumber = true;

    if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    } else {
        char* endPtr = NULL;
        value = std::strtod(literal.c_str(), &endPtr);

        if (*endPtr != '\0' && !((*endPtr == 'f' || *endPtr == 'F') && *(endPtr + 1) == '\0')) {
            std::cout << "Input is not a literal" << std::endl;
        return;
        }
    }
    
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }

    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        int i = static_cast<int>(value);
        std::cout << "int: " << i << std::endl;
    }

    float f = static_cast<float>(value);
    if (std::isnan(f) || std::isinf(f) || (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())) {
        std::cout << "float: " << f << "f" << std::endl;
    } else {
        std::cout << "float: impossible" << std::endl;
    }
    std::cout << "double: " << value << std::endl;
}