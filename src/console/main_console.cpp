#include <iostream>
#include "bus_stop_functions.hpp"
#include "diagonal_throw_functions.hpp"


int main()
{
    bus_stop::bus_draw(4,5);
    std::cout << std::endl << "And the second one: " << std::endl;
    diagonal_throw::throw_draw();
}