#include "../include/Tcar.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tcar::draw()
    {
        std::cout << std::endl <<  "Drawing Vehicle..." << std::endl;
    }

    std::string Tcar::nameCheck()
    {
        std::cout << std::endl << name << std::endl;
        return name;
    }

}