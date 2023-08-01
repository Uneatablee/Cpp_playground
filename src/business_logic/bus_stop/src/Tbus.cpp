#include "../include/Tbus.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tbus::ImoveVehicle(int direction_1)
    {

    }

    void Tbus::IdrawVehicle()
    {
        std::cout << std::endl <<  "Drawing Vehicle..." << std::endl;
    }

    Tbus::~Tbus()
    {
        std::cout << std::endl << "Destroying Bus..." << std::endl;
    }
}