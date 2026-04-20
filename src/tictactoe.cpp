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
}

void Game::computerTurn(const Player* computer)

{
    for (int i = 0; i < 9; i++)

    {
        if (board.isEmpty(i))

        {
            board.setSquare(i, computer->getSymbol());

            std::cout << "Computer chose: " << (i + 1) << "\n";

            break;
        }
    }
}

void Game::start()

{
    Player* turn = player1;

    if (SComputer && FComputer)

        turn = player1;

    int moves = 0;

    while (!winFlag && moves < 9)

    {
        board.display();

        if (SComputer && turn == player2 && FComputer == false)

        {
            computerTurn(player2);
        }

        else if (SComputer && turn == player1 && FComputer == true)

        {
            computerTurn(player1);
        }

        else if (SComputer && turn == player1 && FComputer == false)

        {
            takeTurn(player1);
        }

        else if (SComputer && turn == player2 && FComputer == true)

        {
            takeTurn(player2);
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

    if (!winFlag)

        std::cout << "No Winner, tie!\n";
}


void Game::takeTurn(const Player* currentPlayer)

{
    int choice;

    std::string input;

    while (true)

    {
        std::cout << currentPlayer->getName() << " turn ("

                  << (currentPlayer->getSymbol() == 0 ? "O" : "X")

                  << "): ";

        std::getline(std::cin, input);

        std::stringstream ss(input);

        if (!(ss >> choice) || choice < 1 || choice > 9)

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