#include <catch2/catch_test_macros.hpp>

#include "../src/Player.h"

TEST_CASE("Player getters")

{
    Player p1("X", -1);

    Player p2("O", 0);

    REQUIRE(p1.getName() == "X");

    REQUIRE(p1.getSymbol() == -1);

    REQUIRE(p2.getName() == "O");

    REQUIRE(p2.getSymbol() == 0);
}