#pragma once

#include "Tstop.hpp"
#include "Tterminal.hpp"


namespace cpp_playground::pg_business_logic::bus_stop
{
    class Route final
    {

    public:

        std::vector<std::shared_ptr<Ibus_stop>> stops_list;

        Route()
        {
            stops_list.push_back(std::make_shared<Tterminal>("Bus terminal - 0"));
            stops_list.push_back(std::make_shared<Tstop>("Bus stop - 1"));
            stops_list.push_back(std::make_shared<Tstop>("Bus stop - 2"));
            stops_list.push_back(std::make_shared<Tterminal>("Bus terminal - 3"));
        }

        int startTerminalBusCount()
        {
            return stops_list[0]->counterBussesStop();
        }

        void vehicleCheckout(Ivehicle* vehicle)
        {
            stops_list[0]->addVehicle(vehicle);
        }

        std::vector<std::shared_ptr<Ibus_stop>>::iterator begin(){return stops_list.begin();}
        std::vector<std::shared_ptr<Ibus_stop>>::iterator end(){return stops_list.end();}
        size_t routeSize(){ return stops_list.size();}



    };

}