#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include "Tbus.hpp"
#include "Tcar.hpp"
#include <memory>
#include <vector>
#include "fakeit.hpp"
#include "Idrawable.hpp"

using namespace cpp_playground::pg_business_logic::bus_stop;
using namespace fakeit;


class fake_drawable_implementation;

TEST_CASE("Bus can drive")
{

    Mock<Idrawable> mock;
    When(Method(mock,draw)).Return(true);
    Idrawable* temp = &mock.get();
    // Arrange


    std::vector<std::shared_ptr<Ibus_stop>> stop_list;

    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 0",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 1",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 2",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 3",std::shared_ptr<Idrawable>(temp)));

    std::shared_ptr<Route> route_1 = std::make_shared<Route>(stop_list);
    std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1",std::shared_ptr<Idrawable>(temp));

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
    Mock<Idrawable> mock;
    When(Method(mock,draw)).Return(true);
    Idrawable* temp = &mock.get();
    // Arrange
    std::vector<std::shared_ptr<Ibus_stop>> stop_list;

    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 0",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 1",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 2",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 3",std::shared_ptr<Idrawable>(temp)));

    std::unique_ptr<Route> route_pointer = std::make_unique<Route>(stop_list);
    // Act
    int count = route_pointer -> routeSize();
    // Assert
    REQUIRE(count == 4);
}

TEST_CASE("Newly created vehicle should appear at the bus terminal number 0")
{
    Mock<Idrawable> mock;
    When(Method(mock,draw)).Return(true);
    Idrawable* temp = &mock.get();
    // Arrange
    std::vector<std::shared_ptr<Ibus_stop>> stop_list;

    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 0",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 1",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 2",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 3",std::shared_ptr<Idrawable>(temp)));

    std::shared_ptr<Route> route_1 = std::make_shared<Route>(stop_list);

    std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1",std::shared_ptr<Idrawable>(temp));
    std::unique_ptr<Ivehicle> car = std::make_unique<Tcar>(2, "car_1",std::shared_ptr<Idrawable>(temp));

    bus->assignRoute(route_1);
    car->assignRoute(route_1);

    // Act
    int bus_count = route_1 -> startTerminalBusCount();

    // Assert
    REQUIRE(bus_count == 2);
}

TEST_CASE("When vehicle moves, it adds itself to the next bus stop list and erase form previous")
{
    Mock<Idrawable> mock;
    When(Method(mock,draw)).Return(true);
    Idrawable* temp = &mock.get();
    //Arrange
    std::vector<std::shared_ptr<Ibus_stop>> stop_list;

    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 0",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 1",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tstop>("Stop - 2",std::shared_ptr<Idrawable>(temp)));
    stop_list.push_back(std::make_shared<Tterminal>("Terminal - 3",std::shared_ptr<Idrawable>(temp)));

    std::shared_ptr<Route> route_1 = std::make_shared<Route>(stop_list);

    std::unique_ptr<Ivehicle> bus_1 = std::make_unique<Tbus>(3,"bus_1",std::shared_ptr<Idrawable>(temp));
    bus_1 -> assignRoute(route_1);

    //Act
    int busses_number_1 = route_1 -> busCount(0);
    bus_1 -> moveVehicle(Ivehicle::Movement::Forward);

    int busses_number_at_second_station = route_1 -> busCount(1);
    int busses_number_at_first_station = route_1 -> busCount(0);

    for(int i = 0; i < 3; i++)
    {
        bus_1 -> moveVehicle(Ivehicle::Movement::Forward);
    }

    int busses_number_at_third_station = route_1 -> busCount(2);
    int station_0_number = route_1 -> busCount(0);
    int station_1_number = route_1 -> busCount(1);
    int station_3_number = route_1 -> busCount(3);

    //Assert
    REQUIRE(busses_number_1 == 1);
    REQUIRE(busses_number_at_second_station == 1);
    REQUIRE(busses_number_at_first_station == 0);

    REQUIRE(busses_number_at_third_station == 1);
    REQUIRE(station_0_number == 0);
    REQUIRE(station_1_number == 0);
    REQUIRE(station_3_number == 0);

}

TEST_CASE("Is bus drawing itself")
{
    Mock<Idrawable> mock;
    When(Method(mock,draw)).Return(true);
    Idrawable* temp = &mock.get();
    //Arrange
    std::unique_ptr<Idrawable> bus_drawer = std::make_unique<Tbus>(3,"bus_1",std::shared_ptr<Idrawable>(std::move(temp)));
    auto expected_result = true;


    //Act
    auto result = bus_drawer -> draw(2,"text");

    //Assert
    REQUIRE(result == expected_result);

}