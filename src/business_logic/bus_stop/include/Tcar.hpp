#pragma once
#include "Vehicle_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tcar : virtual public Vehicle_base
    {
    public:

        Tcar(int a, std::string n) : Vehicle_base(a,n)
        {}
        ~Tcar() = default;

    private:
        void draw() override;
        std::string nameCheck() override;
    };
}