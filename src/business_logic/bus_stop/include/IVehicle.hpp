
#pragma once
#include <string>
#include <iostream>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class IVehicle
    {
    public:

        virtual ~IVehicle(){};
        virtual void moveVehicle(int direction) = 0;
        virtual void drawVehicle() = 0;
        virtual std::string name_checkVehicle() = 0;
    };
}