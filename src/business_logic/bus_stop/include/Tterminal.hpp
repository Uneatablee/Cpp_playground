#include "Bus_stop_extended.hpp"

namespace cpp_playground::pg_business_logic::bus_stop
{
    class Tterminal : public Bus_stop_extended
    {
    public:

        Tterminal(std::string stop_name) : Bus_stop_extended(stop_name){}
        ~Tterminal() override;

    private:

        void drawStop() override;
        void refreshStop() override;

    };


}