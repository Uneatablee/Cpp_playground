#pragma once
#include "Vehicle_base.hpp"
#include <memory>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tbus : virtual public Vehicle_base
    {
    public:

        Tbus(int a, std::string n, std::shared_ptr<Idrawable> drawing_component) : Vehicle_base(a,n,drawing_component)
        {}
        ~Tbus() = default;

    private:
    };
}