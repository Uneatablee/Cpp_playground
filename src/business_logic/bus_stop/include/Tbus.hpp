#pragma once
#include "./IVehicle.hpp"
#include <string>
#include <iostream>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tbus : public IVehicle
    {
    public:

        Tbus(int a, std::string n) : IVehicle(a,n)
        {}

        ~Tbus() override;
        void ImoveVehicle(int direction_1) override;
        void IdrawVehicle() override;


    };
}