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

        int startTerminalBusCount();
        void vehicleCheckout(Ivehicle* vehicle);
        int routeSize();
        bool isNextStopBeyondFinal(std::shared_ptr<Ibus_stop> current_position);
        bool isNextStopBeyondStarting(std::shared_ptr<Ibus_stop> current_position);
        std::shared_ptr<Ibus_stop> nextStop(std::shared_ptr<Ibus_stop> current_position,int multiplier);
        std::shared_ptr<Ibus_stop> previousStop(std::shared_ptr<Ibus_stop> current_position,int multiplier);
        std::shared_ptr<Ibus_stop> getTerminalAddress();
    };

}