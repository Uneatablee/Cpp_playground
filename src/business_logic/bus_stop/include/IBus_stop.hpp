#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class IBus_stop
    {
    public:

        virtual ~IBus_stop(){};
        virtual void drawStop() = 0;
        virtual void refreshStop() = 0;

    };


}

