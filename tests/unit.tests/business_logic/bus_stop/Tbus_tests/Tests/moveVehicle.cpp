#include "../Utils/header.hpp"

TEST_CASE("Bus_MoveVehicle")
{

    Mock<Idrawable> Idrawable_mock;
    Mock<IRoute> IRoute_mock;


    SECTION("WhenAssignedToRoute_ShouldBeAbleToMove")
    {
        // Arrange
        Idrawable* Idrawable_mock_instance = &Idrawable_mock.get();

        std::shared_ptr<Route> route_1 = std::make_shared<Route>(createBusStops(std::shared_ptr<Idrawable>(Idrawable_mock_instance), 2));
        std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1",std::shared_ptr<Idrawable>(Idrawable_mock_instance));

        // Act
        bus -> assignRoute(route_1);
        std::string name_of_first_stop = bus -> showStop();

        bus -> moveVehicle(Ivehicle::Movement::Forward);
        std::string name_of_second_stop = bus -> showStop();


        // Assert
        REQUIRE(name_of_first_stop != name_of_second_stop);
    }


}