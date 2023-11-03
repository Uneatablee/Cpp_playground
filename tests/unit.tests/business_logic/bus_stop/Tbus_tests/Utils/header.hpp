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

std::vector<std::shared_ptr<Ibus_stop>> createBusStops( std::shared_ptr<Idrawable> drawer, ushort bus_stops_number);
