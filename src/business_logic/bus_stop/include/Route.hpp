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

        Route();

        int busCount(int stop_number);
        void vehicleCheckout(Ivehicle* vehicle);
        int getStopsCount();
        bool isNextStopBeyondFinal(std::shared_ptr<Ibus_stop> current_position);
        bool isNextStopBeyondStarting(std::shared_ptr<Ibus_stop> current_position);
        std::shared_ptr<Ibus_stop> nextStop(std::shared_ptr<Ibus_stop> current_position,int multiplier);
        std::shared_ptr<Ibus_stop> previousStop(std::shared_ptr<Ibus_stop> current_position,int multiplier);
        std::shared_ptr<Ibus_stop> getTerminalAddress();
    };

}