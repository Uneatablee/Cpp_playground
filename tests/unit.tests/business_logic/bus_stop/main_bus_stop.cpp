#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "Tbus.hpp"
#include "Tcar.hpp"
#include <memory>

using namespace cpp_playground::pg_business_logic::bus_stop;

TEST_CASE("Bus can drive")
{
    // Arrange
    std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1");

    // Act
    int position_1 = (bus->position_outputVehicle());

    bus->moveVehicle(Ivehicle::Movement::Forward);
    int position_2 = (bus->position_outputVehicle());

    bus->moveVehicle(Ivehicle::Movement::Backward);
    int position_3 = (bus->position_outputVehicle());

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
    std::shared_ptr<Route> route_1 = std::make_shared<Route>();

    std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1");
    std::unique_ptr<Ivehicle> car = std::make_unique<Tcar>(2, "car_1");

    bus->assignRoute(route_1);
    car->assignRoute(route_1);

    // Act
    int bus_count = route_1 -> start_terminal_bus_count();

    // Assert
    REQUIRE(bus_count == 2);
}

TEST_CASE("When bus moves beyond terminal it changes direction and goes back toward other terminal")
{
    // Arrange

    // Act

    // Assert
}