#include "../include/Tbus.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tbus::drawVehicle()
    {
        std::cout << std::endl <<  "Drawing Vehicle..." << std::endl;
    }

    std::string Tbus::name_checkVehicle()
    {
        std::cout << std::endl << name << std::endl;
        return name;
    }

}