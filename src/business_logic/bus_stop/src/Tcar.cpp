#include "../include/Tcar.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tcar::drawVehicle()
    {
        std::cout << std::endl <<  "Drawing Vehicle..." << std::endl;
    }

    std::string Tcar::name_checkVehicle()
    {
        std::cout << std::endl << name << std::endl;
        return name;
    }

    int Tcar::position_outputVehicle()
    {
        return current_position;
    }
}