#include "../include/Bus_stop_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    std::string Bus_stop_base::getName()
    {
        return bus_stop_name;
    }

    void Bus_stop_base::addVehicle(Ivehicle* vehicle)
    {
        this -> bus_list.push_back(vehicle);
    }

    void Bus_stop_base::deleteVehicle(Ivehicle* vehicle)
    {
        for(int i=0; i < static_cast<int>(bus_list.size()); i++)
        {
            if(bus_list[i] == vehicle)
            {
                bus_list.erase(bus_list.begin() + i);
                break;
            }
        }
    }

    int Bus_stop_base::getVehiclesCount()
    {
        return this->bus_list.size();
    }

    bool Bus_stop_base::draw(int length, std::string name)
    {
       return drawer -> draw(length,name);
    }

}
