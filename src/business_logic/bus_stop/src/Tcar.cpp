#include "../include/Tcar.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tcar::moveVehicle(Vehicle_extended::Movement direction)
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

    void Tcar::drawVehicle()
    {
        std::cout << std::endl <<  "Drawing Vehicle..." << std::endl;
    }

    Tcar::~Tcar()
    {
        std::cout << std::endl << "Destroying Car..." << std::endl;
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