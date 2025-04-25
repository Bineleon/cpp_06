#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	std::cout << "ScalarConverter copy assignment operator not allowed for non instantiable class" << std::endl;
	(void) rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

// find literal types

bool isChar(std::string literal)
{
	std::string nonDisplay = "ntrbfva0\'\"\\";

	if (literal.length() == 1 && !isdigit(literal.front()))
		return true;
	if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'')
		return true;
	if (literal.length() == 2 && literal.front() == '\\')
	{
		if (nonDisplay.find(literal[1]) != std::string::npos)
			return true;
	}
	if (literal.length() == 4 && literal.front() == '\'' && literal.back() == '\'' && literal[1] == '\\')
	{
		if (nonDisplay.find(literal[2]) != std::string::npos)
			return true;
	}
	return false;
}

bool isSign(char c)
{
	if (c == '+' || c == '-')
		return true;
	return false;
}

bool isInt(std::string literal)
{
	size_t start = 0;
	long long ll;

	if (isSign(literal.front()))
		start++;
	if (start == literal.length())
		return false;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]))
			return false;
	}
	ll = std::atoll(literal.c_str());
	if (ll > INT_MAX || ll < INT_MIN)
		return false;
	return true;
}

bool checkLiteralBody(size_t start, std::string literal, size_t len, bool *pointFound)
{
	for (size_t i = start; i < len; i++)
	{
		if (literal[i] == '.')
		{
			if(!*pointFound)
				*pointFound = true;
			else
				return false;
		}
		if (!isdigit(literal[i]) && (literal[i] != '.'))
			return false;
	}
	return true;
}

bool isFloat(std::string literal)
{
	bool pointFound = false;
	size_t start = 0;

	if (literal.back() != 'f')
		return false;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	if (!isdigit(literal.front()) && literal.front() != '.' && !isSign(literal.front()))
		return false;
	if (isSign(literal.front()))
		start++;
	if (start == literal.length())
		return false;
	if (!checkLiteralBody(start, literal, literal.length() - 1, &pointFound))
		return false;
	return pointFound;
}

bool isDouble(std::string literal)
{
	bool pointFound = false;
	size_t start = 0;

	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	if (!isdigit(literal.front()) && literal.front() != '.' && !isSign(literal.front()))
		return false;
	if (isSign(literal.front()))
		start++;
	if (start == literal.length())
		return false;
	if (!checkLiteralBody(start, literal, literal.length(), &pointFound))
		return false;
	return pointFound;
}

// const char *isPseudoLiteral(std::string literal)
// {
// 	if (literal == "nan" || literal == "nanf"
// 		|| literal == "+inff" || literal == "-inff"
// 		|| literal == "+inf" || literal == "-inf")
// 		return literal.c_str();
// 	return NULL;
// }

// convert literal types

// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

void convertChar(std::string literal)
{

}

void convertInt(std::string literal)
{
	int i = atoi(literal.c_str());
	float f = i;
	double d = i;
	char c;

	std::cout << "char: ";
	if (i >= 0 && i <= 255)
	{
		c = i;
		if (isprint(c))
			std::cout << c << std::endl;
		else
			std::cout << "Non displayable" << std::endl;

	}
	else
		std::cout << "Impossible" << std::endl;


}

void ScalarConverter::convert(std::string literal)
{


	if (isChar(literal))
		std::cout << "IS CHAR\n";
	else
	{
		std::cout << "NOT CHAR\n";
	}
	if (isFloat(literal))
		std::cout << "IS FLOAT\n";
	else
	{
		std::cout << "NOT FLOAT\n";
	}
	if (isDouble(literal))
		std::cout << "IS DOUBLE\n";
	else
	{
		std::cout << "NOT DOUBLE\n";
	}
	if (isInt(literal))
		std::cout << "IS INT\n";
	else
	{
		std::cout << "NOT INT\n";
	}
}
