#pragma once

#include <string>

class Player

{

private:

    std::string name;

    int symbol;

public:

    Player(const std::string& n, int s);

    [[nodiscard]] int getSymbol() const;

    [[nodiscard]] std::string getName() const;
};