#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <climits>
#include <iomanip>
#include <string>

class ScalarConverter
{
	public:
		static void convert(const std::string& literal);
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		~ScalarConverter(void);

};
typedef void (*functPtr)(std::string literal);

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
    NONE
}          t_type;

typedef struct s_literal
{
	t_type      type;
	std::string str;
	functPtr    function;
}              t_literal;

# define RESET "\033[0m"
# define SMRED "\033[0;31m"
# define SMGREEN "\033[0;32m"
# define SMYELLOW "\033[0;33m"
# define SMBLUE "\033[0;34m"
# define SMMAGENTA "\033[0;35m"
# define SMCYAN "\033[0;36m"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"

#endif
