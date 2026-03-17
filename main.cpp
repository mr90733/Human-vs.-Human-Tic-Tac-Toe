#include "src/tictactoe.hpp" //Game Class

#include "src/Player.h"      //Player Class

#include <iostream>          //cout and Cin

#include <string>           //std::string

int main()

{
    std::cout << "Welcome to Tic-Tac-Toe!\n\n";

    std::string playAgain = "yes";  //If Player wants to keep playing

    while (playAgain == "yes")

    {
        Player p1("Player X", -1);
                                            // Player X (-1) and Player O (0)
        Player p2("Player O", 0);

        Game ttt(&p1, &p2);

        ttt.start();               // Start game

        while (true)
                         //Loop for Players if they want to play again
        {
            std::cout << "Would you like to play again (yes/no)? ";

            std::cin >> playAgain;

            std::cin.ignore();

            if (playAgain == "yes" || playAgain == "no")

                break;

            else

                std::cout << "\nThat is not a valid entry!\n\n";
        }
    }

    return 0;
}