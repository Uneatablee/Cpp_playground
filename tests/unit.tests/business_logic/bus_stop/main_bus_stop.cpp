#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "Tbus.hpp"
#include "Tcar.hpp"
#include <memory>

using namespace cpp_playground::pg_business_logic::bus_stop;

TEST_CASE( "Bus can drive" )
{
    //Arrange
    std::unique_ptr<IVehicle> pointer_1 = std::make_unique<Tbus>(3,"bus_1");


    //Act
    int position_1 = (pointer_1 -> position_outputVehicle());

    pointer_1 -> moveVehicle(IVehicle::Movement::Forward);
    int position_2 = (pointer_1 -> position_outputVehicle());

    pointer_1 -> moveVehicle(IVehicle::Movement::Backward);
    int position_3 = (pointer_1 -> position_outputVehicle());


    //Assert
    REQUIRE(position_1 != position_2);
    REQUIRE(position_3 == position_1);
}

TEST_CASE( )
{
    //Arrange

    //Act

    //Assert
}