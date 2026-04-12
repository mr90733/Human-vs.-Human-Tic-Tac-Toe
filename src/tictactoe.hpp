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

    bool SComputer;

    bool FComputer;

public:

    Game(Player* p1, Player* p2, bool vsComp = false, bool compFirst = false);

    void start();

    void takeTurn(const Player* currentPlayer);

    void computerTurn(const Player* computer);

    bool checkWin();
};