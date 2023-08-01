#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "Tbus.hpp"

using namespace cpp_playground::pg_business_logic::bus_stop;

TEST_CASE( "Bus_can_drive" )
{
    //Arrange
    Tbus Bus_1(3,"bus_1");
    IVehicle* pointer_1 = &Bus_1;


    //Act
    pointer_1 -> moveVehicle(0);

    //Assert
}

TEST_CASE( "When_bus_move_forward_it_should_change_position" )
{
    //Arrange
    Tbus Bus_1(3,"bus_1");
     IVehicle* pointer_1 = &Bus_1;

    //Act
    pointer_1 -> moveVehicle(1);

    //Assert
}