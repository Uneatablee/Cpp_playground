#include "Idrawable.hpp"

using namespace cpp_playground::pg_business_logic::bus_stop;

class bus_vehicle_drawable : public Idrawable
{
private:
    /* data */
public:
    bus_vehicle_drawable(/* args */);
    ~bus_vehicle_drawable();

    bool draw() override;
};

bool bus_vehicle_drawable::draw()
{
    return true;
}
