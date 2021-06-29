#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board
{
protected:
    short m_size;

public:
    std::vector<int> map;

    Board();
    ~Board();
    short size() const {return m_size;}
    void clear();
    void print();
    char gridSymbol(int ); // convert 1 to X, -1 to O, 0 to space
    std::vector<int> emptyCells() const;
    bool isFull();
};

#endif // BOARD_H
