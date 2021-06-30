#ifndef ABSTRACT_GAMER_H
#define ABSTRACT_GAMER_H
#include <vector>
#include <iostream>
#include <cstdlib>

#include "board_class/board.h"

class AbstractGamer{
protected:
    int m_symbol;

public:
    virtual bool nextStep(Board& ) = 0;
    int getSymbol();
    bool win(Board& );
};

#endif // ABSTRACT_GAMER_H
