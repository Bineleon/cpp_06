#include "utils.hpp"

#include <iomanip>

void printHeader(const std::string& str)
{
	int size = 50;
	int totalPad = size - str.size();
	(totalPad < 0) ? totalPad = 0 : totalPad;
	int lPad = totalPad / 2;
	int rPad = totalPad - lPad;

	std::cout << std::endl << SMGREEN;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(lPad + str.size()) << str << std::setw(rPad) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << RESET << std::endl;
}

int main(void)
{
	std::srand(time(0));
	Base *p1 = generate();
	Base & p2 = *p1;
	
	printHeader("Test: Identifying from pointer");
	std::cout << SMYELLOW << "Indentifying Base *p1..." << RESET<< std::endl;
	identify(p1);

	printHeader("Test: Identifying from reference");
	std::cout << SMYELLOW << "Indentifying Base & p2..." << RESET<< std::endl;
	identify(p2);

	delete p1;

    return 0;
}
