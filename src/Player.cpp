#include "Player.h"


Player::Player(const std::string& n, int s)
{
    name = n;

    symbol = s;
}

int Player::getSymbol() const

{
    return symbol;
}


std::string Player::getName() const

{
    return name;
}