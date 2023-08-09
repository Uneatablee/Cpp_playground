#pragma once

#include "Tstop.hpp"
#include "Tterminal.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Route final
    {
    private:

        std::vector<std::unique_ptr<Ibus_stop>> stops_list;

    public:
        Route()
        {
            stops_list.push_back(std::make_unique<Tterminal>("Bus terminal - 0"));
            stops_list.push_back(std::make_unique<Tstop>("Bus stop - 1"));
            stops_list.push_back(std::make_unique<Tstop>("Bus stop - 2"));
            stops_list.push_back(std::make_unique<Tterminal>("Bus terminal - 3"));
        }

        int stop_list_count(){ return stops_list.size(); }

        int start_terminal_bus_count()
        {
            return stops_list[0]->counterBussesStop();
        }

        void operator+=(Ivehicle* vehicle_pointer)
        {
            stops_list[0]->addVehicle(vehicle_pointer);
        }

    };

}