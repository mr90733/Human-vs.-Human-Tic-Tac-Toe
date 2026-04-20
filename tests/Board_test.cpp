#include <catch2/catch_test_macros.hpp>

#include "../src/Board.h"

TEST_CASE("Board start")

{
    Board board;

    for (int i = 0; i < 9; i++)

    {
        REQUIRE(board.isEmpty(i));
    }
}

TEST_CASE("setSquare update")

{
    Board board;

    board.setSquare(0, -1);

    REQUIRE(board.isEmpty(0) == false);
}

TEST_CASE("Prevents detecting empty as win scenario")

{
    Board board;

    for (int i = 0; i < 9; i++)

    {
        REQUIRE(board.isEmpty(i));
    }
}