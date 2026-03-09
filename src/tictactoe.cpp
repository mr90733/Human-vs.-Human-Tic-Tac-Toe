#include "tictactoe.hpp"

#include <iostream>

#include <sstream>

Game::Game(Player* p1, Player* p2)

{
    player1 = p1;

    player2 = p2;

    winFlag = false;
}

void Game::start()

{
    Player* turn = player1;

    int moves = 0;

    while (!winFlag && moves < 9)

    {
        board.display();

        takeTurn(turn);

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

void Game::takeTurn(Player* currentPlayer)

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

        if (!(ss >> choice) || !(ss.eof()) || choice < 1 || choice > 9)

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