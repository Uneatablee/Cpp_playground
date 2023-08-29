#include "../include/Vehicle_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Vehicle_base::assignRoute(std::shared_ptr<Route> route)
    {
        this -> current_route = route;
        current_route -> vehicleCheckout(this);

        current_position = current_route -> stops_list[0];
    }

    void Vehicle_base::moveVehicle(Ivehicle::Movement direction)
    {
        switch(direction)
        {
            case Vehicle_base::Movement::Forward:


            break;

            case Vehicle_base::Movement::Backward:

            break;
        }
    }

    std::string Vehicle_base::showStop()
    {
        return current_position -> getName();
    }

}
