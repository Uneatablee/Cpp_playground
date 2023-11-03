#include "../include/Vehicle_base.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    void Vehicle_base::assignRoute(std::shared_ptr<IRoute> route)
    {
        this -> current_route = route;
        current_route -> vehicleCheckout(this);

        current_position = current_route -> getTerminalAddress();
    }

    bool Vehicle_base::moveVehicle(Ivehicle::Movement direction)
    {
        if(current_position == nullptr)
        return false;

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

            current_route -> deleteVehicle(this, current_position);
            current_position = current_route -> nextStop(current_position, phrase_multiplier);
            current_route -> addVehicle(this, current_position);
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

            current_route -> deleteVehicle(this, current_position);
            current_position = current_route -> previousStop(current_position, phrase_multiplier);
            current_route -> addVehicle(this , current_position);
            break;
        }

        return true;
    }

    std::string Vehicle_base::showStop()
    {
        return current_position -> getName(); //Change into Route-Only dependency
    }

    std::string Vehicle_base::getName()
    {
        std::cout << std::endl << name << std::endl;
        return name;
    }

    bool Vehicle_base::draw(int length, std::string name)
    {
       return drawer -> draw(length,name);
    }

}
