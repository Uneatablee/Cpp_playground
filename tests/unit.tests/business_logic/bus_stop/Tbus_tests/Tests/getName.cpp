#include "../Utils/header.hpp"

TEST_CASE("getName returns name")
{

    //Arrange

    Mock<Idrawable> mock;

    SECTION("Should return name")
    {
        //Arrange
        Idrawable* temp = &mock.get();
        std::unique_ptr<Ivehicle> bus = std::make_unique<Tbus>(3, "bus_1",std::shared_ptr<Idrawable>(std::move(temp)));

        auto expected_result = "bus_1";

        //Act
        auto result = bus -> getName();

        //Assert
        REQUIRE(result == expected_result);

    }

}