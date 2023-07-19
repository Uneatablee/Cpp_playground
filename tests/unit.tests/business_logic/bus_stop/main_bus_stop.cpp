#include <iostream>
#include "bus_stop_functions.hpp"
#include <catch2/catch_test_macros.hpp>



TEST_CASE( "Bus_stop library working test" )
{
    REQUIRE(cpp_playground::pg_business_logic::bus_stop::bus_draw(10,2) == 5);
}
