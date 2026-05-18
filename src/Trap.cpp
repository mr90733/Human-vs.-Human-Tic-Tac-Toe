#include "Trap.h"

#include <iostream>

Trap::Trap()

{
    enabled = false;

    cell = -1;

    std::random_device rd;

    gen = std::mt19937(rd());
}

void Trap::enable()

{
    enabled = true;

    std::uniform_int_distribution<> dist(0, 8);

    cell = dist(gen);

    std::cout << "Hidden trap has been placed on the board!\n";
}

void Trap::disable()

{
    enabled = false;

    cell = -1;
}

bool Trap::checkHit(int index)

{
    if (!enabled) return false;

    if (index == cell)

    {
        std::cout << "Trap activated at position " << (index + 1) << "! lose turn\n";

        enabled = false;

        return true;
    }

    return false;
}