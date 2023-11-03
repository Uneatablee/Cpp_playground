#pragma once

#include "Tstop.hpp"
#include "Tterminal.hpp"
#include "IRoute.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Route : virtual public IRoute
    {
    private:
        std::vector<std::shared_ptr<Ibus_stop>> stops_list;
    public:

        Route(std::vector<std::shared_ptr<Ibus_stop>> list);

        int busCount(int stop_number) override;
        void vehicleCheckout(Ivehicle* vehicle) override;
        int getStopsCount() override;
        bool isNextStopBeyondFinal(std::shared_ptr<Ibus_stop> current_position) override;
        bool isNextStopBeyondStarting(std::shared_ptr<Ibus_stop> current_position) override;
        std::shared_ptr<Ibus_stop> nextStop(std::shared_ptr<Ibus_stop> current_position,int multiplier) override;
        std::shared_ptr<Ibus_stop> previousStop(std::shared_ptr<Ibus_stop> current_position,int multiplier) override;
        std::shared_ptr<Ibus_stop> getTerminalAddress() override;
        void addVehicle(Ivehicle* vehicle_address, std::shared_ptr<Ibus_stop> stop_address) override;
        void deleteVehicle(Ivehicle* vehicle_address, std::shared_ptr<Ibus_stop> stop_address) override;

    };

}