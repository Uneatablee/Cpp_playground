#include "../include/Tterminal.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    Tterminal::~Tterminal(){}

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

    void Tterminal::addVehicle(IVehicle* vehicle)
    {
        this->bus_list.push_back(vehicle);
    }

}