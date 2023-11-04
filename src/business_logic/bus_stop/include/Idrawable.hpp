#pragma once

#include <iostream>

namespace cpp_playground::pg_business_logic::bus_stop
{

    class Idrawable
    {
    public:

        Idrawable() = default;
        virtual ~Idrawable() = default;

        Idrawable(const Idrawable& object) = default;
        Idrawable& operator=(const Idrawable& object) = default;

        Idrawable(Idrawable&& object) = default;
        Idrawable& operator=(Idrawable && object) = default;

        virtual bool draw(int,std::string) = 0;

    };
}