#pragma once

#include "Tstop.hpp"
#include "Tterminal.hpp"


namespace cpp_playground::pg_business_logic::bus_stop
{
    class Route final
    {
    private:
        std::vector<std::shared_ptr<Ibus_stop>> stops_list;
    public:

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

        int routeSize()
        {
            return stops_list.size();
        }

        bool isBeyondFinal(std::shared_ptr<Ibus_stop> current_position)
        {
            auto it = stops_list.begin();
            for(it;it != stops_list.end(); it++)
            {
                if(*it == current_position) break;
            }

            auto starting_terminal_pointer = stops_list.begin();

            if((starting_terminal_pointer - (it + 1)) <= -(static_cast<std::ptrdiff_t>(stops_list.size()))) return true;
            else return false;
        }

        bool isBeyondStarting(std::shared_ptr<Ibus_stop> current_position)
        {
            auto it = stops_list.begin();
            for(it;it != stops_list.end(); it++)
            {
                if(*it == current_position) break;
            }

            auto starting_terminal_pointer = stops_list.begin();

            if(starting_terminal_pointer - (it - 1) > 0) return true;
            else return false;
        }

        std::shared_ptr<Ibus_stop> nextStop(std::shared_ptr<Ibus_stop> current_position,int multiplier)
        {
            auto it = stops_list.begin();
            for(it;it != stops_list.end(); it++)
            {
                if(*it == current_position) break;
            }

            it += multiplier;
            return *it;
        }

        std::shared_ptr<Ibus_stop> previousStop(std::shared_ptr<Ibus_stop> current_position,int multiplier)
        {
            auto it = stops_list.begin();
            for(it;it != stops_list.end(); it++)
            {
                if(*it == current_position) break;
            }

            it -= multiplier;
            return *it;
        }

        std::shared_ptr<Ibus_stop> getTerminalAddress()
        {
            return stops_list[0];
        }



    };

}