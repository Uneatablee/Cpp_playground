#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "Tbus.hpp"
#include "Tcar.hpp"
#include <memory>

using namespace cpp_playground::pg_business_logic::bus_stop;

TEST_CASE("Bus can drive")
{
    // Arrange
    std::shared_ptr<Route> route_1 = std::make_shared<Route>();
    std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1");

    bus -> assignRoute(route_1);

    // Act

    std::string name_of_first_stop = bus -> showStop();

    bus->moveVehicle(Ivehicle::Movement::Forward);
    std::string name_of_second_stop = bus -> showStop();

    bus->moveVehicle(Ivehicle::Movement::Backward);
    std::string name_of_third_stop = bus -> showStop();


    // Assert

    REQUIRE(name_of_first_stop != name_of_second_stop);
    REQUIRE(name_of_first_stop == name_of_third_stop);

}

TEST_CASE("Bus_stops base count should be 4")
{
    // Arrange
    std::unique_ptr<Route> route_pointer = std::make_unique<Route>();
    // Act
    int count = route_pointer -> routeSize();
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
    int bus_count = route_1 -> startTerminalBusCount();

    // Assert
    REQUIRE(bus_count == 2);
}

TEST_CASE("When bus moves beyond terminal it changes direction and goes back toward other terminal")
{
    // Arrange
    std::shared_ptr<Route> route_1 = std::make_shared<Route>();
    std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1");
    std::unique_ptr<Ivehicle> bus_1 = std::make_unique<Tbus>(3, "bus_2");

    // Act

    //Forward movement testing------------------------------------------------------

    bus -> assignRoute(route_1);
    bus_1 -> assignRoute(route_1);

    for(int i=0; i<3; i++) bus -> moveVehicle(Ivehicle::Movement::Forward);
    std::string stop_name_1 = bus -> showStop();

    bus -> moveVehicle(Ivehicle::Movement::Forward);
    bus -> moveVehicle(Ivehicle::Movement::Forward);
    std::string stop_name_2 = bus -> showStop();

    bus -> moveVehicle(Ivehicle::Movement::Forward);
    bus -> moveVehicle(Ivehicle::Movement::Forward);
    std::string stop_name_3 = bus -> showStop();

    bus_1 -> moveVehicle(Ivehicle::Movement::Forward);
    std::string stop_name_4 = bus_1 -> showStop();

    //Backward movement testing------------------------------------------------------

    std::unique_ptr<Ivehicle> car_1 = std::make_unique<Tcar>(2, "car_1");
    std::unique_ptr<Ivehicle> car_2 = std::make_unique<Tcar>(2, "car_2");

    car_1 -> assignRoute(route_1);
    car_2 -> assignRoute(route_1);

    car_1 -> moveVehicle(Ivehicle::Movement::Forward);
    car_1 -> moveVehicle(Ivehicle::Movement::Forward);
    std::string car_position_1 = car_1 -> showStop();

    car_2 -> moveVehicle(Ivehicle::Movement::Backward);
    car_2 -> moveVehicle(Ivehicle::Movement::Backward);
    std::string car_position_2 = car_2 -> showStop();


    for(int i = 0; i < 4; i++)
    {
        car_2 -> moveVehicle(Ivehicle::Movement::Backward);
    }
    std::string car_position_3 = car_2 -> showStop();

    // Assert

    REQUIRE(stop_name_1 == stop_name_2);
    REQUIRE(stop_name_3 == stop_name_4);
    REQUIRE(car_position_1 == car_position_2);
    REQUIRE(car_position_1 == car_position_3);

}