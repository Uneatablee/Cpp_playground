#pragma once
#include "Vehicle_extended.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tbus : public Vehicle_extended
    {
    public:

        Tbus(int a, std::string n) : Vehicle_extended(a,n)
        {}
        ~Tbus() override;

    private:
        void moveVehicle(int direction_1) override;
        void drawVehicle() override;


    };
}