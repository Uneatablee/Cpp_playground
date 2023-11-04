#pragma once
#include "header.hpp"

    using namespace cpp_playground::pg_business_logic::bus_stop;

    class Menu final
    {

    private:

        std::vector<std::shared_ptr<Route>> routes_list;

    public:

        std::unique_ptr<screen> main_screen = std::make_unique<screen>(' ');

        Menu() = default;

        void menuClear();
        void screenRefresh();
        void vehicleSection();
        void RouteSection();
        void exit();

    };