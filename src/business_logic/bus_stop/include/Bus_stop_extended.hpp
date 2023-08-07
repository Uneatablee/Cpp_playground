#pragma once
#include "IBus_stop.hpp"
#include "IVehicle.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Bus_stop_extended : public IBus_stop
    {
    protected:

        Bus_stop_extended(std::string nam) : bus_stop_name(nam){}

        std::vector<IVehicle*> bus_list;
        std::string bus_stop_name;
        int coordinate_x;
        int coordinate_y;


    };


}
