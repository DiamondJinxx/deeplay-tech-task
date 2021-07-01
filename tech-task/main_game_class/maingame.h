#ifndef MAINGAME_H
#define MAINGAME_H
#include "gamer_class/smart_gamer.h"
#include "gamer_class/gamer.h"
#include "board_class/board.h"
#include <fstream>
class MainGame
{
    Board b_;
    Gamer *g_;
    SmartGamer *sg_;

public:
    int winner_;
    std::string saveFileName_;
    MainGame();
    void step(); // one step of game
    bool win(Board&, int gamerSymbol); // check win of gamer , Board& param needed for minimax recursive algo
    bool gameover(); // checking borad emptys
    bool run();
    void firstGamerStep();
    void secondGamerStep();
    void printBoard();
    bool save(std::string fn, int part_number,int winner,int steps); //save game result
    void reset();

    int minimax(Board& b, int gamer); // minimax algo without alpha-beta pruning
    int getBestCell(int gamer); // change best cell for gamer
};

#endif // MAINGAME_H
