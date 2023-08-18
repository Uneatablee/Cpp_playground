#pragma once
#include "Bus_stop_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tterminal : virtual public Bus_stop_base
    {
    public:

        Tterminal(std::string stop_name) : Bus_stop_base(stop_name)
        {std::cout << "Created Terminal" << std::endl;}

        ~Tterminal() = default;

    private:

        void drawStop() override;
        void refreshStop() override;
        int counterBussesStop() override;
        void addVehicle(Ivehicle*) override;
    };


}