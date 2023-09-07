#include "../include/Tstop.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Tstop::draw()
    {

    }

    int Tstop::counterBussesStop()
    {
        return this->bus_list.size();
    }

    void Tstop::addVehicle(Ivehicle* vehicle)
    {
        this->bus_list.push_back(vehicle);
    }

}