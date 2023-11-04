#include "../Utils/header.hpp"

Mock<Idrawable> Idrawable_mock;

TEST_CASE("WhenBusIsAssigned_ShouldAppearAtStartingTerminal")
{
    When(Method(Idrawable_mock,draw)).Return(true);
    Idrawable* Idrawable_mock_instance = &Idrawable_mock.get();

    // Arrange
    std::shared_ptr<Route> route_1 = std::make_shared<Route>(createBusStops(std::shared_ptr<Idrawable>(Idrawable_mock_instance), 2));

    std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1",std::shared_ptr<Idrawable>(Idrawable_mock_instance));
    std::unique_ptr<Ivehicle> car = std::make_unique<Tcar>(2, "car_1",std::shared_ptr<Idrawable>(Idrawable_mock_instance));

    bus -> assignRoute(route_1);
    car -> assignRoute(route_1);

    std::string expected_result = "Terminal - 0";

    std::string result_stop_bus = bus -> showStop();
    std::string result_stop_car = car -> showStop();

    REQUIRE(result_stop_bus == expected_result);
    REQUIRE(result_stop_car == expected_result);

}