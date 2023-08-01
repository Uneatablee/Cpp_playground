#include "../include/Tbus.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tbus::moveVehicle(int direction_1)
    {

        direction_1 = 2;
    }

    void Tbus::drawVehicle()
    {
        std::cout << std::endl <<  "Drawing Vehicle..." << std::endl;
    }

    Tbus::~Tbus()
    {
        std::cout << std::endl << "Destroying Bus..." << std::endl;
    }
}