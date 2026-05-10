#include "src/tictactoe.hpp"

#include "src/Player.h"

#include <iostream>

#include <string>


int main()

{
    std::cout << " Welcome to Tic-Tac-Toe!\n ";

    std::string playAgain = "yes";

    while (playAgain == "yes")

    {
        int choice;

        std::cout << "What kind of game would you like to play?\n";

        std::cout << "1. Human vs Human\n";

        std::cout << "2. Human vs Computer\n";

        std::cout << "3. Computer vs Human\n";

        std::cout << "What is your selection? ";

        while (true)
        {
            std::cin >> choice;

            if (std::cin.fail())

            {
                std::cin.clear();

                std::cin.ignore(10000, '\n');

                std::cout << "Invalid input. Choose 1, 2 or 3: ";

                continue;
            }

            if (choice >= 1 && choice <= 3)

                break;

            std::cout << "Invalid selection! Please choose 1, 2, or 3: ";
        }

        Player p1("Player X", -1);

        Player p2("Player O", 0);

        Game* ttt;

        if (choice == 1)

        {
            ttt = new Game(&p1, &p2, false, false);
        }

        else if (choice == 2)

        {
            ttt = new Game(&p1, &p2, true, false);
        }

        else

        {
            ttt = new Game(&p1, &p2, true, true);
        }

        int trapChoice;

        std::string input;

        std::cin.ignore(10000, '\n');

        std::cout << "\nWould you like to include a trap cell?\n";

        std::cout << "1. Yes\n";

        std::cout << "2. No\n";

        while (true)

        {
            std::cout << "Selection:";

            std::getline(std::cin, input);

            if (input == "1")

            {
                trapChoice = 1;

                break;
            }

            else if (input == "2")

            {
                trapChoice = 2;

                break;
            }

            else

            {
                std::cout << "Invalid selection! Select 1 or 2 only.\n";
            }
        }

        ttt->enableTrap(trapChoice == 1);

        ttt->start();

        delete ttt;

        while (true)

        {
            std::cout << " Would you like to play again (yes/no)? ";

            std::cin >> playAgain;

            std::cin.ignore(1000, '\n');

            if (playAgain == "yes" || playAgain == "no")

                break;
            else

                std::cout << "Invalid input!\n";
        }
    }

    std::cout << "Goodbye!\n";

    return 0;
}