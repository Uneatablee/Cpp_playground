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
        if(current_position == nullptr)
        return;

        auto it = current_route -> begin();
        for(it;it != current_route -> end(); it++)
        {
            if(*it == current_position) break;
        }

        auto starting_terminal_pointer = current_route -> begin();
        int phrase_multiplier;

        switch(direction)
        {
        case Vehicle_base::Movement::Forward:

            if(current_phrase == Ivehicle::Phrase::Normal)
            {

                if((starting_terminal_pointer - (it + 1)) <= -(static_cast<std::ptrdiff_t>(current_route -> routeSize())))
                current_phrase = Ivehicle::Phrase::Reversed;
            }
            else
            {
                if(starting_terminal_pointer - (it - 1) > 0)
                current_phrase = Ivehicle::Phrase::Normal;
            }

            if(current_phrase == Ivehicle::Phrase::Normal) phrase_multiplier = 1;
            else phrase_multiplier = -1;

            it += (1 * phrase_multiplier);
            current_position = *it;
            break;

        case Vehicle_base::Movement::Backward:

            if(current_phrase == Ivehicle::Phrase::Normal)
            {
                if(starting_terminal_pointer - (it - 1) > 0)
                current_phrase = Ivehicle::Phrase::Reversed;
            }
            else
            {
                if(starting_terminal_pointer - (it + 1) <= -(static_cast<std::ptrdiff_t>(current_route -> routeSize())))
                current_phrase = Ivehicle::Phrase::Normal;
            }

            if(current_phrase == Ivehicle::Phrase::Normal) phrase_multiplier = 1;
            else phrase_multiplier = -1;

            it -= (1 * phrase_multiplier);
            current_position = *it;
            break;
        }
    }

    std::string Vehicle_base::showStop()
    {
        return current_position -> getName();
    }

}
