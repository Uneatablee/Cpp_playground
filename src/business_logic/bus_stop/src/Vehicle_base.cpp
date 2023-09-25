#include "../include/Vehicle_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Vehicle_base::assignRoute(std::shared_ptr<Route> route)
    {
        this -> current_route = route;
        current_route -> vehicleCheckout(this);

        current_position = current_route -> getTerminalAddress();
    }

    void Vehicle_base::moveVehicle(Ivehicle::Movement direction)
    {
        if(current_position == nullptr)
        return;

        int phrase_multiplier;

        switch(direction)
        {
        case Vehicle_base::Movement::Forward:

            if(current_phrase == Ivehicle::Phrase::Normal)
            {

                if(current_route -> isNextStopBeyondFinal(current_position))
                {
                    current_phrase = Ivehicle::Phrase::Reversed;
                }
            }
            else
            {
                if(current_route -> isNextStopBeyondStarting(current_position))
                {
                    current_phrase = Ivehicle::Phrase::Normal;
                }
            }

            if(current_phrase == Ivehicle::Phrase::Normal)
            {
                phrase_multiplier = 1;
            }
            else
            {
                phrase_multiplier = -1;
            }

            current_position -> deleteVehicle(this);
            current_position = current_route -> nextStop(current_position, phrase_multiplier);
            current_position -> addVehicle(this);
            break;

        case Vehicle_base::Movement::Backward:

            if(current_phrase == Ivehicle::Phrase::Normal)
            {
                if(current_route -> isNextStopBeyondStarting(current_position))
                {
                    current_phrase = Ivehicle::Phrase::Reversed;
                }
            }
            else
            {
                if(current_route -> isNextStopBeyondFinal(current_position))
                {
                    current_phrase = Ivehicle::Phrase::Normal;
                }

            }

            if(current_phrase == Ivehicle::Phrase::Normal)
            {
                phrase_multiplier = 1;
            }
            else
            {
                phrase_multiplier = -1;
            }

            current_position -> deleteVehicle(this);
            current_position = current_route -> previousStop(current_position, phrase_multiplier);
            current_position -> addVehicle(this);
            break;
        }
    }

    std::string Vehicle_base::showStop()
    {
        return current_position -> getName();
    }

    std::string Vehicle_base::nameCheck()
    {
        std::cout << std::endl << name << std::endl;
        return name;
    }

}
