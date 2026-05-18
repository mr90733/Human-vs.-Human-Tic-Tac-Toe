#pragma once

#include "Player.h"

#include "Board.h"

#include "Trap.h"

class Game
{
private:

    Player* player1;

    Player* player2;

    Board board;

    Trap trap;

    bool winFlag;

    bool player1Computer;

    bool player2Computer;

    bool trapEnabled;

public:

    Game(Player* p1, Player* p2, bool vsComp = false, bool compFirst = false);

    void start();

    bool takeTurn(const Player* currentPlayer);

    bool computerTurn(const Player* computer);

    bool checkWin();

    Board& getBoard();

    void enableTrap(bool enable);
};