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

bool isChar(std::string literal)
{
	if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'')
		return true;
	if (literal.length() == 4 && )
	return false;
}

bool isSignChar(char c)
{
	if (c == '+' || c == '-')
		return true;
	return false;
}

bool isInt(std::string literal)
{
	size_t start = 0;
	long long ll;

	if (isSignChar(literal.front()))
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
	if (!isdigit(literal.front()) && literal.front() != '.' && !isSignChar(literal.front()))
		return false;
	if (isSignChar(literal.front()))
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

	if (!isdigit(literal.front()) && literal.front() != '.' && !isSignChar(literal.front()))
		return false;
	if (isSignChar(literal.front()))
		start++;
	if (start == literal.length())
		return false;
	if (!checkLiteralBody(start, literal, literal.length(), &pointFound))
		return false;
	return pointFound;
}

void ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
	{
		std::cerr << "TODO" << std::endl;
		return;
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
