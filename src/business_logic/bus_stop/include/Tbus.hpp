#pragma once
#include "Vehicle_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tbus : virtual public Vehicle_base
    {
    public:

        Tbus(int a, std::string n) : Vehicle_base(a,n)
        {

        }
        ~Tbus() = default;

    private:
        void drawVehicle() override;
        std::string name_checkVehicle() override;
    };
}