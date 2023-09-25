#pragma once
#include "Vehicle_base.hpp"
#include <memory>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tcar : virtual public Vehicle_base
    {
    public:

        Tcar(int a, std::string n, std::shared_ptr<Idrawable> d) : Vehicle_base(a,n,d)
        {}
        ~Tcar() = default;

    private:

    };
}