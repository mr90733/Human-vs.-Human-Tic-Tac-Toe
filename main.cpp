#include "src/tictactoe.hpp"

#include "src/Player.h"

#include <iostream>

#include <string>

int main()

{
    std::cout << "Welcome to Tic-Tac-Toe!\n\n";

    std::string playAgain = "yes";

    while (playAgain == "yes")
    {
        Player p1("Player X", -1);
        Player p2("Player O", 0);

        Game ttt(&p1, &p2);
        ttt.start();

        while (true)
        {
            std::cout << "Would you like to play again (yes/no)? ";
            std::cin >> playAgain;

            if (playAgain == "yes" || playAgain == "no")
                break;
            else
                std::cout << "\nThat is not a valid entry!\n\n";
        }
    }

    return 0;
}