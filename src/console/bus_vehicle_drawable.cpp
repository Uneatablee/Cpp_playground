#include "Idrawable.hpp"

using namespace cpp_playground::pg_business_logic::bus_stop;

class bus_vehicle_drawable : public Idrawable
{
public:
    bus_vehicle_drawable() = default;
    ~bus_vehicle_drawable() = default;

    bool draw(int, std::string) override;
};

bool bus_vehicle_drawable::draw(int length, std::string name)
{


    return true;
}
