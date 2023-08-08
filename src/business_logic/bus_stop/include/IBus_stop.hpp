#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "IVehicle.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class IBus_stop
    {
    public:

        virtual ~IBus_stop(){};
        virtual void drawStop() = 0;
        virtual void refreshStop() = 0;
        virtual int counterBussesStop() = 0;
        virtual void addVehicle(IVehicle*) = 0;

    };


}

