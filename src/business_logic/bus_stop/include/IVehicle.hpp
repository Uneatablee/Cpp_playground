
#pragma once
#include <string>
#include <iostream>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class IVehicle
    {
    protected:

        int length;
        std::string name;
        int current_position;     //number of current bus_stop
        int direction;

    public:

        IVehicle(int vlenght, std::string v_name) : length(vlenght), name(v_name)
        {std::cout << std::endl << "Creating Vehicle..";}
        virtual ~IVehicle(){};
        virtual void ImoveVehicle(int direction) = 0;
        virtual void IdrawVehicle() = 0;
    };
}