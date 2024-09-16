#include <iostream>
#include <cmath>

bool isFloatLiteral(const std::string& str) {
	std::cout << "float" << std::endl;
    if (str.compare("nanf") == 0 || str.compare("-inff") == 0 || str.compare("inff") == 0)
		return 1;
	char* end;
    std::strtof(str.c_str(), &end);
    return *end == 'f' && end[1] == '\0';
}

bool isDoubleLiteral(const std::string& str) {
	std::cout << "double" << std::endl;
	if (str.compare("nan") == 0 || str.compare("-inf") == 0 || str.compare("inf") == 0)
		return 1;
    char* end;
    std::strtod(str.c_str(), &end);
    return *end == '\0';
}

bool isCharLiteral(const std::string& str) {
	std::cout << "char" << std::endl;
    return str.length() == 1;
}

bool isIntLiteral(const std::string& str) {
	std::cout << "int" << std::endl;
	for (int i = 0; i < str.length(); ++i)
		if (!isdigit(str[i]))
			return (0);
    char* end;
    long val = std::strtol(str.c_str(), &end, 10);
    return *end == '\0' && val >= INT_MIN && val <= INT_MAX;
}
