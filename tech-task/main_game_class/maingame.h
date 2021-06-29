#ifndef MAINGAME_H
#define MAINGAME_H
#include "gamer_class/smart_gamer.h"
#include "gamer_class/gamer.h"
#include "board_class/board.h"

class MainGame
{
    Board b_;
    Gamer *g_;
    SmartGamer *sg_;
public:
    bool gamerun;
    MainGame();
    void step(); // one step of game
    bool win(int gamerSymbol); // check win of gamer
    bool gameover(); // checking borad emptys
    bool run();
    void firstGamerStep();
    void secondGamerStep();
    void printBoard();
};

#endif // MAINGAME_H
