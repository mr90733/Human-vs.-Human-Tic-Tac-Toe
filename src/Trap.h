#pragma once

#include <random>

class Trap
{
private:
    bool enabled;
    int cell;
    std::mt19937 gen;

public:
    Trap();

    void enable();

    void disable();

    bool checkHit(int index);
};