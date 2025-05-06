#include "Serializer.hpp"
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
	printHeader("Test : Serialize");
	std::cout << SMYELLOW << "Creating Data origin..." << RESET<< std::endl;

	Data origin;
	origin.str = "Coucou";

	std::cout << "Str member in origin is \"" << origin.str << "\"" << std::endl;

	std::cout << "The value of &origin is " << &origin << '\n';

	std::cout << SMYELLOW << "Serializing &origin in raw..." << RESET<< std::endl;
	uintptr_t raw = Serializer::serialize(&origin);

	std::cout << "The value of raw is " << raw << '\n';

	std::cout << SMYELLOW << "Deserializing raw in Data *ptr..." << RESET<< std::endl;

	Data *ptr = Serializer::deserialize(raw);

	std::cout << "The value of ptr is " << ptr << '\n';

	std::cout << "Str member in ptr is \"" << ptr->str << "\"" << std::endl;

    return 0;
}
