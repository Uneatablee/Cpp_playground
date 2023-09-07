
#pragma once
#include <string>
#include <iostream>
#include "Route.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Ivehicle
    {
    public:
        enum class Movement{Forward, Backward};
        enum class Phrase{Normal, Reversed};

        Ivehicle() = default;
        virtual ~Ivehicle() = default;

        Ivehicle(Ivehicle&&) = default;
        Ivehicle& operator=(Ivehicle&&) = default;

        Ivehicle(const Ivehicle&) = default;
        Ivehicle& operator=(const Ivehicle&) = default;

        virtual void moveVehicle(Movement) = 0;
        virtual void draw() = 0;
        virtual std::string nameCheck() = 0;
        virtual void assignRoute(std::shared_ptr<Route>) = 0;
        virtual std::string showStop() = 0;
    };
}