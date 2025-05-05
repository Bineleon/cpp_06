#include "Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Serializer default constructor not allowed for non instantiable class" << std::endl;
}

Serializer::Serializer(const Serializer& src)
{
    std::cout << "Serializer copy constructor not allowed for non instantiable class" << std::endl;
    *this = src;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    std::cout << "Serializer copy assignment operator not allowed for non instantiable class" << std::endl;
    (void) rhs;
    return *this;
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std::endl;
}
