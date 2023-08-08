#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "Route.hpp"
#include "Tbus.hpp"
#include "Tcar.hpp"
#include <memory>

using namespace cpp_playground::pg_business_logic::bus_stop;

TEST_CASE("Bus can drive")
{
    // Arrange
    std::unique_ptr<IVehicle> pointer_1 = std::make_unique<Tbus>(3, "bus_1");

    // Act
    int position_1 = (pointer_1->position_outputVehicle());

    pointer_1->moveVehicle(IVehicle::Movement::Forward);
    int position_2 = (pointer_1->position_outputVehicle());

    pointer_1->moveVehicle(IVehicle::Movement::Backward);
    int position_3 = (pointer_1->position_outputVehicle());

    // Assert
    REQUIRE(position_1 != position_2);
    REQUIRE(position_3 == position_1);
}

TEST_CASE("Bus_stops base count should be 4")
{
    // Arrange
    std::unique_ptr<Route> route_pointer = std::make_unique<Route>();
    // Act
    int count = route_pointer->stop_list_count();
    // Assert
    REQUIRE(count == 4);
}

TEST_CASE("Newly created vehicle should appear at the bus terminal number 0")
{
    // Arrange
    Route route_1;
    Tbus bus_1(3,"bus_1");
    Tcar car_1(2,"car_1");

    route_1 += &bus_1;
    route_1 += &car_1;


    // Act
    int bus_count = route_1.start_terminal_bus_count();

    // Assert
    REQUIRE(bus_count == 2);
}