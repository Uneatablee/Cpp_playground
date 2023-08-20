#include "../include/Vehicle_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Vehicle_base::assignRoute(std::shared_ptr<Route> route)
    {
        this -> current_route = route;
        current_route -> vehicleCheckout(this);
    }

    void Vehicle_base::moveVehicle(Ivehicle::Movement direction)
    {
        switch(direction)
        {
            case Vehicle_base::Movement::Forward:
            current_position += 1;
            break;

            case Vehicle_base::Movement::Backward:
            current_position -= 1;
            break;
        }
    }

}
