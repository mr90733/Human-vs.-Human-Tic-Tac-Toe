#pragma once

#include "Player.h"

#include "Board.h"

class Game

{
private:

    Player* player1;

    Player* player2;

    Board board;

    bool winFlag;

public:

    Game(Player* p1, Player* p2);

    void start();

    void takeTurn(Player* currentPlayer);

    bool checkWin();
};