#include "Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& src)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = src;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    std::cout << "Serializer copy assignment operator called" << std::endl;
        // copy attributs here
    return *this;
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer destructor called" << std::endl;
}
