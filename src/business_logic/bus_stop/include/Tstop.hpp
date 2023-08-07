#include "Bus_stop_extended.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tstop : public Bus_stop_extended
    {
    public:

        Tstop(std::string stop_name) : Bus_stop_extended(stop_name){}
        ~Tstop() override;

    private:

        void drawStop() override;
        void refreshStop() override;

    };


}
