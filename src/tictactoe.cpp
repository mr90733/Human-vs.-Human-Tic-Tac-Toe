#include "tictactoe.hpp"

#include <iostream>

#include <random>

Game::Game(Player* p1, Player* p2, bool vsComp, bool compFirst)
{
    player1 = p1;

    player2 = p2;

    winFlag = false;

    player1Computer = false;

    player2Computer = false;

    trapEnabled = false;

    if (vsComp)

    {
        if (compFirst)

            player1Computer = true;

        else
            player2Computer = true;
    }
}

void Game::enableTrap(bool enable)

{
    trapEnabled = enable;

    if (trapEnabled)

        trap.enable();
}

bool Game::computerTurn(const Player* computer)
{
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(0, 8);

    int index;

    do {

        index = dist(gen);

    } while (!board.isEmpty(index));

    if (trap.checkHit(index))

    {
        std::cout << "Computer hit TRAP at position " << (index + 1) << "! loses turn\n";

        return false;
    }

    board.setSquare(index, computer->getSymbol());

    std::cout << "Computer chose: " << (index + 1) << "\n";

    return true;
}

void Game::start()

{
    Player* turn = player1;

    int moves = 0;

    while (!winFlag && moves < 9)

    {
        board.display();

        std::cout << turn->getName() << " turn:" << std::endl;

        bool success = false;

        if (turn == player1)
        {
            if (player1Computer)

                success = computerTurn(player1);

            else

                success = takeTurn(player1);
        }

        else

        {
            if (player2Computer)

                success = computerTurn(player2);

            else

                success = takeTurn(player2);
        }

        if (success)

        {
            moves++;

            if (checkWin())

            {
                board.display();

                std::cout << "Winner: " << turn->getName() << "\n";

                return;
            }

            turn = (turn == player1) ? player2 : player1;
        }

        else

        {
            std::cout << "Turn lost due to trap!\n";

            turn = (turn == player1) ? player2 : player1;
        }
    }

    board.display();

    std::cout << "No Winner, tie!\n";
}

bool Game::takeTurn(const Player* currentPlayer)

{
    std::string input;

    int choice;

    std::getline(std::cin, input);

    try {

        choice = std::stoi(input);

    } catch (...) {

        return false;
    }

    if (choice < 1 || choice > 9)

        return false;

    int index = choice - 1;

    if (!board.isEmpty(index))

        return false;

    if (trap.checkHit(index))

        return false;

    board.setSquare(index, currentPlayer->getSymbol());

    return true;
}

bool Game::checkWin()

{
    int* b = &board.getSquareRef(0);

    for (int i = 0; i < 9; i += 3)

        if (b[i] == b[i+1] && b[i+1] == b[i+2] && b[i] != 0)

            return true;

    for (int i = 0; i < 3; i++)

        if (b[i] == b[i+3] && b[i+3] == b[i+6] && b[i] != 0)

            return true;

    if (b[0]==b[4] && b[4]==b[8] && b[0]!=0)

        return true;

    if (b[2]==b[4] && b[4]==b[6] && b[2]!=0)

        return true;

    return false;
}

Board& Game::getBoard()

{
    return board;
}