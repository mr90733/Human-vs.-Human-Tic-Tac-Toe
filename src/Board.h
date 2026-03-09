#pragma once

class Board

{

private:

    int squares[9];

public:

    Board();

    void display() const;

    [[nodiscard]] bool isEmpty(int position) const;

    void setSquare(int position, int value);

    int& getSquareRef(int position);
};