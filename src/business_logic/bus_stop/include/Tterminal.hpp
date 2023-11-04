#pragma once
#include "Bus_stop_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tterminal : virtual public Bus_stop_base
    {
    public:

        Tterminal(std::string stop_name, std::shared_ptr<Idrawable> drawing_component) : Bus_stop_base(stop_name, drawing_component)
        {}

        ~Tterminal() = default;
    };

}