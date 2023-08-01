#include <iostream>
#include "diagonal_throw_functions.hpp"
#include "Tbus.hpp"

using namespace cpp_playground::pg_business_logic::bus_stop;
int main()
{
    cpp_playground::pg_business_logic::bus_stop::Tbus Bus_1(3,"Bus_1");
    IVehicle* pointer_1 = &Bus_1;
    pointer_1 -> drawVehicle();

}