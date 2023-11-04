#include "header.hpp"

std::vector<std::shared_ptr<Ibus_stop>> createBusStops( std::shared_ptr<Idrawable> drawer, ushort bus_stops_number = 0)
{
    std::vector<std::shared_ptr<Ibus_stop>> stops_list;
    stops_list.push_back(std::make_shared<Tterminal>("Terminal - 0", drawer));

    for(int i=0; i < bus_stops_number; i++)
    {
        stops_list.push_back(std::make_shared<Tstop>("Bus_stop" + std::to_string(i+1), drawer));
    }

    stops_list.push_back(std::make_shared<Tterminal>("Terminal" + std::to_string(bus_stops_number + 1), drawer));
    return stops_list;
}



