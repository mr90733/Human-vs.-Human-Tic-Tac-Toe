#include "Trap.h"

#include <iostream>

#include <random>

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

bool Trap::checkHit(int index) const

{
    return enabled && index == cell;
}