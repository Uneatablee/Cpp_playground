#pragma once
#include "Bus_stop_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tstop : virtual public Bus_stop_base
    {
    public:

        Tstop(std::string stop_name) : Bus_stop_base(stop_name)
        {std::cout << "Creating stop" << std::endl;}

        ~Tstop() = default;

    private:

        void draw() override;
    };

}
