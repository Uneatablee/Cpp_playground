#pragma once

#include "Ivehicle.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{

    class Vehicle_base : virtual public Ivehicle
    {
    protected:

        Vehicle_base(int l,std::string n,int c = 0) : length(l), name(n), current_position(c)
        {}
        ~Vehicle_base() = default;

        Vehicle_base(const Vehicle_base& object) = delete;
        Vehicle_base& operator=(const Vehicle_base& object) = delete;

        Vehicle_base(Vehicle_base&& object) = default;
        Vehicle_base& operator=(Vehicle_base&& object) = default;

        void moveVehicle(Ivehicle::Movement) override;
        void assignRoute(Route*) override;

        int length;
        std::string name;
        int current_position;     //number of current bus_stop
        int direction_of_moving;
        Route* current_route;

    };
}