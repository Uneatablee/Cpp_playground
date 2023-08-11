
#pragma once
#include <string>
#include <iostream>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Ivehicle
    {
    public:
        enum class Movement{Forward, Backward};

        virtual ~Ivehicle() = default;

        Ivehicle(Ivehicle&&) = default;
        Ivehicle& operator=(Ivehicle&&) = default;

        Ivehicle(const Ivehicle&) = default;
        Ivehicle& operator=(const Ivehicle&) = default;

        virtual void moveVehicle(Movement) = 0;
        virtual void drawVehicle() = 0;
        virtual std::string name_checkVehicle() = 0;
        virtual int position_outputVehicle() = 0;
    };
}