#include <iostream>
#include "diagonal_throw_functions.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Bus_stop library working test" )
{
    REQUIRE(cpp_playground::pg_business_logic::diagonal_throw::throw_draw(3,5) == 10.0);
}