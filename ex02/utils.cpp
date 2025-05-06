#include "utils.hpp"

Base * genA(void)
{
	Base *a = new A;
	return a;
}

Base * genB(void)
{
	Base *b = new B;
	return b;
}

Base * genC(void)
{
	Base *c = new C;
	return c;
}

Base * generate(void)
{
	functPtr children[3] = { genA, genB, genC };
	int idx = std::rand() % 3;
	functPtr randomFunc = children[idx];
	return randomFunc();
}


void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "Type of the object pointed to by p: " << GREEN << "\'A\'\n" << RESET;
		return;
	}
	B *b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "Type of the object pointed to by p: " << GREEN << "\'B\'\n" << RESET;
		return;
	}
	C *c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "Type of the object pointed to by p: " << GREEN << "\'C\'\n" << RESET;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		A & a = dynamic_cast<A &>(p);
		std::cout << "Type of the object referenced by p: " << GREEN << "\'A\'\n" << RESET;
		(void) a;
	}
	catch(const std::exception& e){}
	try
	{
		B & b = dynamic_cast<B &>(p);
		std::cout << "Type of the object referenced by p: " << GREEN << "\'B\'\n" << RESET;
		(void) b;
	}
	catch(const std::exception& e){}
	try
	{
		C & c = dynamic_cast<C &>(p);
		std::cout << "Type of the object referenced by p: " << GREEN << "\'C\'\n" << RESET;
		(void) c;
	}
	catch(const std::exception& e){}
	
	return;
}