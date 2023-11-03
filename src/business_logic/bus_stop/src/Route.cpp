#include "../include/Route.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    Route::Route(std::vector<std::shared_ptr<Ibus_stop>> list) : stops_list(list)
    {}

    int Route::busCount(int stop_number)
    {
        return stops_list[stop_number]->getVehiclesCount();
    }

    void Route::vehicleCheckout(Ivehicle* vehicle)
    {
        stops_list[0]->addVehicle(vehicle);
    }

    int Route::getStopsCount()
    {
        return stops_list.size();
    }

    bool Route::isNextStopBeyondFinal(std::shared_ptr<Ibus_stop> current_position)
    {
        auto it = stops_list.begin();
        for(;it != stops_list.end(); it++)
        {
            if(*it == current_position) break;
        }

        auto starting_terminal_pointer = stops_list.begin();

        if((starting_terminal_pointer - (it + 1)) <= -(static_cast<std::ptrdiff_t>(stops_list.size())))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool Route::isNextStopBeyondStarting(std::shared_ptr<Ibus_stop> current_position)
    {
        auto it = stops_list.begin();
        for(;it != stops_list.end(); it++)
        {
            if(*it == current_position) break;
        }

        auto starting_terminal_pointer = stops_list.begin();

        if(starting_terminal_pointer - (it - 1) > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::shared_ptr<Ibus_stop> Route::nextStop(std::shared_ptr<Ibus_stop> current_position,int multiplier)
    {
        auto it = stops_list.begin();
        for(;it != stops_list.end(); it++)
        {
            if(*it == current_position) break;
        }

        it += multiplier;
        return *it;
    }

    std::shared_ptr<Ibus_stop> Route::previousStop(std::shared_ptr<Ibus_stop> current_position,int multiplier)
    {
        auto it = stops_list.begin();
        for(;it != stops_list.end(); it++)
        {
            if(*it == current_position) break;
        }

        it -= multiplier;
        return *it;
    }

    std::shared_ptr<Ibus_stop> Route::getTerminalAddress()
    {
        return stops_list[0];
    }

    void Route::addVehicle(Ivehicle* vehicle_address, std::shared_ptr<Ibus_stop> stop_address)
    {
        stop_address -> addVehicle(vehicle_address);
    }

    void Route::deleteVehicle(Ivehicle* vehicle_address, std::shared_ptr<Ibus_stop> stop_address)
    {
        stop_address -> deleteVehicle(vehicle_address);
    }
}