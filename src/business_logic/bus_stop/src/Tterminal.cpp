#include "../include/Tterminal.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tterminal::drawStop()
    {
    }

    void Tterminal::refreshStop()
    {
    }

    int Tterminal::counterBussesStop()
    {
        return this->bus_list.size();
    }

    void Tterminal::addVehicle(Ivehicle *vehicle)
    {
        this->bus_list.push_back(vehicle);
    }

}