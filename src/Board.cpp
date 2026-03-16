#include "Board.h"

#include <iostream>

Board::Board() : squares{1,2,3,4,5,6,7,8,9}  //Constructor for board design
{
}

void Board::display() const
{
    std::cout << "\n";
    for (int i = 0; i < 9; i++)  //Loop, display X and O in squares
    {
        if (squares[i] == -1)
            std::cout << " X ";
        else if (squares[i] == 0)
            std::cout << " O ";
        else
            std::cout << " " << squares[i] << " ";

        if ((i + 1) % 3 != 0)
            std::cout << "|";

        if ((i + 1) % 3 == 0 && i != 8)
            std::cout << "\n---+---+---\n";
    }
    std::cout << "\n\n";
}

bool Board::isEmpty(int position) const
{
    return squares[position] != -1 && squares[position] != 0;
}

void Board::setSquare(int position, int value)
{
    squares[position] = value;
}

int& Board::getSquareRef(int position)
{
    return squares[position];
}