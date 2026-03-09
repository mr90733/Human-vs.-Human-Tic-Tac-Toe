#pragma once

#include <string>

class Player

{

private:

    std::string name;

    int symbol;

public:

    Player(const std::string& n, int s);

    int getSymbol() const;

    std::string getName() const;
};