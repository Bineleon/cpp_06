#include "ScalarConverter.hpp"
#include <iomanip>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << RED << "Error: please follow this format : <exe_name> <string_to_represent>" << RESET << std::endl;
        return 1;
    }

    // ScalarConverter c; // Uncomment to verify non-instantiabilty

    ScalarConverter::convert(av[1]);

    return 0;
}
