#include "Board.h"

#include <iostream>

Board::Board()
{
    for (int & square : squares)

        square = 0;
}

void Board::display() const

{
    std::cout << "\n";

    for (int i = 0; i < 9; i++)

    {
        if (squares[i] == 1)

            std::cout << " X ";

        else if (squares[i] == 2)

            std::cout << " O ";

        else

            std::cout << " " << (i + 1) << " ";

        if ((i + 1) % 3 != 0)

            std::cout << "|";

        if ((i + 1) % 3 == 0)

            std::cout << "\n---+---+---\n";
    }

    std::cout << "\n";
}

bool Board::isEmpty(int position) const

{
    return squares[position] == 0;
}

void Board::setSquare(int position, int value)

{
    squares[position] = value;
}

int& Board::getSquareRef(int position)

{
    return squares[position];
}