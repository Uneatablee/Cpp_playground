#pragma once

#include "Tstop.hpp"
#include "Tterminal.hpp"


namespace cpp_playground::pg_business_logic::bus_stop
{
    class IRoute
    {
    public:

        IRoute() = default;
        virtual ~IRoute() = default;

        IRoute(IRoute &&) = default;
        IRoute &operator=(IRoute &&) = default;

        IRoute(const IRoute &) = default;
        IRoute &operator=(const IRoute &) = default;

        virtual int busCount(int stop_number) = 0;
        virtual void vehicleCheckout(Ivehicle* vehicle) = 0;
        virtual int getStopsCount() = 0;
        virtual bool isNextStopBeyondFinal(std::shared_ptr<Ibus_stop> current_position) = 0;
        virtual bool isNextStopBeyondStarting(std::shared_ptr<Ibus_stop> current_position) = 0;
        virtual std::shared_ptr<Ibus_stop> nextStop(std::shared_ptr<Ibus_stop> current_position,int multiplier) = 0;
        virtual std::shared_ptr<Ibus_stop> previousStop(std::shared_ptr<Ibus_stop> current_position,int multiplier) = 0;
        virtual std::shared_ptr<Ibus_stop> getTerminalAddress() = 0;
        virtual void addVehicle(Ivehicle* vehicle_address, std::shared_ptr<Ibus_stop> stop_address) = 0;
        virtual void deleteVehicle(Ivehicle* vehicle_address, std::shared_ptr<Ibus_stop> stop_address) = 0;
    };

}