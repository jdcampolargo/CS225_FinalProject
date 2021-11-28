#include "catch2/catch.hpp"
#include "include/airport.h"

// using Airport::Airport;

TEST_CASE("Airport Tests") {
    SECTION("Sanity check", "[adder]") {
        Airport a = Airport();

        REQUIRE(a.getNum() == 1);
    }
}