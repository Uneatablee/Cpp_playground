#include "../include/Bus_stop_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    std::string Bus_stop_base::getName()
    {
        return bus_stop_name;
    }

    void Bus_stop_base::addVehicle(Ivehicle * vehicle)
    {
        this->bus_list.push_back(vehicle);
    }

    int Bus_stop_base::counterBussesStop()
    {
        return this->bus_list.size();
    }


}
