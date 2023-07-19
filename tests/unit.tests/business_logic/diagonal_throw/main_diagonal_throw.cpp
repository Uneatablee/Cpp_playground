#include <iostream>
#include "diagonal_throw_functions.hpp"
#include <catch2/catch_test_macros.hpp>


TEST_CASE( "Diagonal_throw library working test" )
{
    REQUIRE(cpp_playground::pg_business_logic::diagonal_throw::throw_draw(3,5) == 10.0);
}

