#include "Player.h"


Player::Player(const std::string& n, int s)
{
    name = n; // Set Name

    symbol = s; // Set Symbol x and O
}

int Player::getSymbol() const

{
    return symbol;
}
                                     //Returns players Symbol

std::string Player::getName() const

{
    return name;
}