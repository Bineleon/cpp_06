#ifndef INVALIDLITERALEXCEPTION_HPP
#define INVALIDLITERALEXCEPTION_HPP

#include <iostream>

class InvalidLiteralException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Please enter a valid number to convert";
		}
};

#endif
