
#include <iostream>

#include <sstream>

#include <catch2/catch_test_macros.hpp>

#include "../src/tictactoe.hpp"

#include "../src/Player.h"

TEST_CASE("Game creation")

{
    Player p1("Player X", 1);

    Player p2("Player O", 2);

    REQUIRE_NOTHROW(Game(&p1, &p2, false, false));
}

TEST_CASE("checkWin False on empty board")

{
    Player p1("X", 1);

    Player p2("O", 2);

    Game game(&p1, &p2);

    REQUIRE(game.checkWin() == false);
}

TEST_CASE("Computer move does not crash")

{
    Player p1("X", 1);

    Player p2("O", 2);

    Game game(&p1, &p2, true, false);

    REQUIRE_NOTHROW(game.computerTurn(&p2));
}

TEST_CASE("Multiple computer moves do not crash")

{
    Player p1("X", 1);

    Player p2("O", 2);

    Game game(&p1, &p2, true, false);

    REQUIRE_NOTHROW(game.computerTurn(&p2));

    REQUIRE_NOTHROW(game.computerTurn(&p1));
}

TEST_CASE("Diagonal win")

{
    Player p1("X", 1);

    Player p2("O", 2);

    Game game(&p1, &p2, false, false);

    std::istringstream input("1\n2\n5\n3\n9\n");

    std::cin.rdbuf(input.rdbuf());

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    REQUIRE(game.checkWin() == true);
}

TEST_CASE("Vertical win")

{
    Player p1("X", 1);

    Player p2("O", 2);

    Game game(&p1, &p2, false, false);

    std::istringstream input("1\n2\n4\n5\n7\n");

    std::cin.rdbuf(input.rdbuf());

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    REQUIRE(game.checkWin() == true);
}

TEST_CASE("Horizontal win")

{
    Player p1("X", 1);

    Player p2("O", 2);

    Game game(&p1, &p2, false, false);

    std::istringstream input("1\n4\n2\n5\n3\n");

    std::cin.rdbuf(input.rdbuf());

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    REQUIRE(game.checkWin() == true);
}

TEST_CASE("Trap flow")

{
    Player p1("X", 1);

    Player p2("O", 2);

    Game game(&p1, &p2, false, false);

    game.enableTrap(true);

    std::istringstream input(

        "1\n2\n3\n4\n5\n"
    );

    std::cin.rdbuf(input.rdbuf());

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    game.takeTurn(&p2);

    game.takeTurn(&p1);

    REQUIRE(game.checkWin() == false);
}