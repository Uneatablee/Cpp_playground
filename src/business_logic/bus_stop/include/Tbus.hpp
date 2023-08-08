#pragma once
#include "Vehicle_extended.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tbus : virtual public Vehicle_extended
    {
    public:

        Tbus(int a, std::string n) : Vehicle_extended(a,n)
        {

        }
        ~Tbus() override;

    private:
        void moveVehicle(IVehicle::Movement direction) override;
        void drawVehicle() override;
        std::string name_checkVehicle() override;
        int position_outputVehicle() override;

    };
}