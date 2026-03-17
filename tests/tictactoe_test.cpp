#include <catch2/catch_test_macros.hpp>

#include "../src/tictactoe.hpp"

#include "../src/Player.h"

TEST_CASE("Game creation")

{
    Player p1("Player X", -1);

    Player p2("Player O", 0);

    REQUIRE_NOTHROW(Game(&p1, &p2));
}

TEST_CASE("checkWin False on empty board")

{
    Player p1("Player X", -1);

    Player p2("Player O", 0);

    Game game(&p1, &p2);

    REQUIRE(game.checkWin() == false);
}
