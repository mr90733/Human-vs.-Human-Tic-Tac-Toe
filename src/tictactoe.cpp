#include "tictactoe.hpp"

#include <iostream>

#include <sstream>

Game::Game(Player* p1, Player* p2, bool vsComp, bool compFirst)

{
    player1 = p1;

    player2 = p2;

    winFlag = false;

    SComputer = vsComp;

    FComputer = compFirst;

    trapEnabled = false;
}

Board& Game::getBoard()

{
    return board;
}

void Game::enableTrap(bool enable)

{
    trapEnabled = enable;

    if (trapEnabled)

    {
        trap.enable();
    }
}

void Game::computerTurn(const Player* computer)

{
    for (int i = 0; i < 9; i++)

    {
        if (board.isEmpty(i))

        {
            if (trap.checkHit(i))

            {
                std::cout << "Computer hit the trap! loses turn!\n";

                return;
            }

            board.setSquare(i, computer->getSymbol());

            std::cout << "Computer chose: " << (i + 1) << "\n";

            return;
        }
    }
}

void Game::start()

{
    Player* turn = player1;

    int moves = 0;

    while (!winFlag && moves < 9)

    {
        board.display();

        if (SComputer)

        {
            if (turn == player1 && FComputer)

                computerTurn(player1);

            else if (turn == player2 && !FComputer)

                computerTurn(player2);

            else

                takeTurn(turn);
        }

        else

        {
            takeTurn(turn);
        }

        winFlag = checkWin();

        if (winFlag)

        {
            board.display();

            std::cout << "Winner: " << turn->getName() << "\n";

            return;
        }

        turn = (turn == player1) ? player2 : player1;

        moves++;
    }

    board.display();

    std::cout << "No Winner, tie!\n";
}

void Game::takeTurn(const Player* currentPlayer)
{
    std::string input;

    int choice;

    while (true)

    {
        std::cout << currentPlayer->getName() << " turn: ";

        std::getline(std::cin, input);

        try

        {
            choice = std::stoi(input);
        }

        catch (...)
        {
            std::cout << "Invalid move. Try again!\n";

            continue;
        }

        if (choice < 1 || choice > 9)

        {
            std::cout << "Invalid move. Try again!\n";

            continue;
        }

        int index = choice - 1;

        if (!board.isEmpty(index))

        {
            std::cout << "Invalid move. Try again!\n";

            continue;
        }

        if (trap.checkHit(index))

        {
            std::cout << "Oh no! Trap activated!"

                      << currentPlayer->getName()

                      << " loses turn!\n";
            return;
        }

        board.setSquare(index, currentPlayer->getSymbol());

        break;
    }
}

bool Game::checkWin()

{
    int* b = &board.getSquareRef(0);

    for (int i = 0; i < 9; i += 3)

        if (*(b + i) == *(b + i + 1) && *(b + i + 1) == *(b + i + 2))

            return true;

    for (int i = 0; i < 3; i++)

        if (*(b + i) == *(b + i + 3) && *(b + i + 3) == *(b + i + 6))

            return true;

    if (*(b + 0) == *(b + 4) && *(b + 4) == *(b + 8)) return true;

    if (*(b + 2) == *(b + 4) && *(b + 4) == *(b + 6)) return true;

    return false;
}