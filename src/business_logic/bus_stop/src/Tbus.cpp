#include "../include/Tbus.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tbus::moveVehicle(Vehicle_extended::Movement direction)
    {
        switch(direction)
        {
            case Vehicle_extended::Movement::Forward:
            current_position += 1;
            break;

            case Vehicle_extended::Movement::Backward:
            current_position -= 1;
            break;
        }

    }

    void Tbus::drawVehicle()
    {
        std::cout << std::endl <<  "Drawing Vehicle..." << std::endl;
    }

    Tbus::~Tbus()
    {
        std::cout << std::endl << "Destroying Bus..." << std::endl;
    }

    std::string Tbus::name_checkVehicle()
    {
        std::cout << std::endl << name << std::endl;
        return name;
    }

    int Tbus::position_outputVehicle()
    {
        return current_position;
    }
}