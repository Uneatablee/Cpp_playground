#pragma once
#include "Ibus_stop.hpp"
#include "Idrawable.hpp"
#include <memory>

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Ivehicle;

    class Bus_stop_base : virtual public Ibus_stop , virtual public Idrawable
    {
    protected:

        Bus_stop_base(std::string nam, std::shared_ptr<Idrawable> drawing_component) : bus_stop_name(nam), drawer(drawing_component)
        {}
        ~Bus_stop_base() = default;

        Bus_stop_base(const Bus_stop_base& object) = default;
        Bus_stop_base& operator=(const Bus_stop_base& object) = default;

        Bus_stop_base(Bus_stop_base&& object) = default;
        Bus_stop_base& operator=(Bus_stop_base&& object) = default;


        std::vector<Ivehicle*> bus_list;
        std::string bus_stop_name;
        int coordinate_x;
        int coordinate_y;
        std::shared_ptr<Idrawable> drawer;

        std::string getName() override;
        void addVehicle(Ivehicle*) override;
        void deleteVehicle(Ivehicle*) override;
        int getVehiclesCount() override;

    };


}
