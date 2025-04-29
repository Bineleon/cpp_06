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

std::string isChar(std::string literal)
{
    std::string str;

	if (literal.length() == 1 && !isdigit(literal.front()))
        str = literal;
    if (literal.length() == 3 && literal.front() == '\'' && literal.back() == '\'')
        str = literal[1];
	if (str.empty())
	    return "NULL";
    return str;
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

bool isPseudoFLiteral(std::string literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	return false;
}

bool isPseudoDLiteral(std::string literal)
{
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	return false;
}

// convert literal types

// char: Non displayable
// int: 0
// float: 0.0f
// double: 0.0

std::string intToChar(int i)
{
    char c;
    std::string str;

    if (i >= 0 && i <= 255)
	{
		c = i;
		if (isprint(c))
            str = c;
		else
            str = "Non displayable";
        return str;
	}
    return "Impossible";
}

void displayConv(char c, int i, float f, double d, bool of)
{
    std::cout << "char: ";
    if (c)
        std::cout << c << std::endl;
    else if (!of)
        std::cout << intToChar(i) << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout << "int: ";
    if (!of)
        std::cout << i << std::endl;
    else
        std::cout << "Impossible" << std::endl;
    std::cout  << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void displayPseudoL(std::string literal)
{
    std::string c;
    std::string i;
    std::string f = literal;
    std::string d = literal;

    if (isPseudoFLiteral(literal))
        d.pop_back();
    else
       f.push_back('f');
    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

void convertChar(std::string literal)
{
    char c = literal.front();
    int i = static_cast<int>(c);
    float f = static_cast<float>(i);
	double d = static_cast<double>(i);

    displayConv(c, i, f, d, false);
}

void convertInt(std::string literal)
{
	int i = atoi(literal.c_str());
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	displayConv(0, i, f ,d, false);
}

void convertFloat(std::string literal)
{
    int i;
	float f;
    double d;
    bool oflow;

    f = std::stof(literal, NULL);
    d = static_cast<double>(f);
    oflow = false;

    if (static_cast<long long>(f) > INT_MAX)
        oflow = true;
    i = f;
	displayConv(0, i, f ,d, oflow);
}

void convertDouble(std::string literal)
{
	int i;
	double d;
	float f;
    bool oflow;

    d = std::stod(literal, NULL);
	f = static_cast<float>(d);
    oflow = false;

    if (static_cast<long long>(f) > INT_MAX)
        oflow = true;
    i = d;
	displayConv(0, i, f ,d, oflow);
}

void ScalarConverter::convert(std::string literal)
{
    if (isPseudoDLiteral(literal) || isPseudoFLiteral(literal))
        displayPseudoL(literal);
	if (isChar(literal) != "NULL")
		convertChar(isChar(literal));
	if (isFloat(literal))
		convertFloat(literal);
	if (isDouble(literal))
		convertDouble(literal);
	if (isInt(literal))
		convertInt(literal);
    else
        std::cout << "Please enter a valid number to convert" << std::endl;
}
