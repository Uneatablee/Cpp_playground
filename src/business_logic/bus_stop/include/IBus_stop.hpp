#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Ivehicle.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Ibus_stop
    {
    public:

        virtual ~Ibus_stop() = default;

        Ibus_stop(Ibus_stop&&) = default;
        Ibus_stop& operator=(Ibus_stop&&) = default;

        Ibus_stop(const Ibus_stop&) = default;
        Ibus_stop& operator=(const Ibus_stop&) = default;

        virtual void drawStop() = 0;
        virtual void refreshStop() = 0;
        virtual int counterBussesStop() = 0;
        virtual void addVehicle(Ivehicle*) = 0;

    };


}

