#pragma once

#include "Ivehicle.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{

    class Vehicle_base : virtual public Ivehicle
    {
    protected:

        Vehicle_base(int l,std::string n) : length(l), name(n)
        {}
        ~Vehicle_base() = default;

        Vehicle_base(const Vehicle_base& object) = default;
        Vehicle_base& operator=(const Vehicle_base& object) = default;

        Vehicle_base(Vehicle_base&& object) = default;
        Vehicle_base& operator=(Vehicle_base&& object) = default;

        void moveVehicle(Ivehicle::Movement) override;
        void assignRoute(std::shared_ptr<Route>) override;
        std::string showStop() override;

        int length;
        std::string name;
        std::shared_ptr<Ibus_stop> current_position = nullptr;
        std::shared_ptr<Route> current_route = nullptr;
        Phrase current_phrase = Ivehicle::Phrase::Normal;

    };
}