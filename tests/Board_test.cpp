#include <catch2/catch_test_macros.hpp>

#include "../src/Board.h"

TEST_CASE("Board Start")

{
    for (int i = 0; i < 9; i++)

        {

        Board board;

        REQUIRE(board.isEmpty(i));
    }
}


TEST_CASE("setSquare update")

{
    Board board;

    board.setSquare(0, -1);

    REQUIRE(board.isEmpty(0) == false);
}