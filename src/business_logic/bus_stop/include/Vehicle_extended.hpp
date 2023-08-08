#pragma once

#include "IVehicle.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{

    class Vehicle_extended : public IVehicle
    {
    protected:

        Vehicle_extended(int l,std::string n,int c = 0) : length(l), name(n), current_position(c)
        {

        }

        int length;
        std::string name;
        int current_position;     //number of current bus_stop
        int direction_of_moving;

    };
}