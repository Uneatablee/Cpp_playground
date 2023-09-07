#pragma once
#include "header.hpp"


namespace cpp_playground::pg_business_logic::bus_stop
{
    class Menu final
    {

    private:

        std::vector<std::shared_ptr<Route>> routes_list;
        std::unique_ptr<screen> main_screen = std::make_unique<screen>(' ');

    public:




    };
}