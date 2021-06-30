#include <iostream>
//#include "gamer_class/abstract_gamer.h"
#include "gamer_class/gamer.h"
#include "gamer_class/smart_gamer.h"
#include "board_class/board.h"
#include "main_game_class/maingame.h"
#include <cstdlib>
using namespace std;

void printMap(std::vector<std::vector<char>>& map)
{
    for(auto v : map)
    {
        std:: cout << '|';
        for(auto c : v)
            std:: cout  <<  c << '|';

        std::cout << '\n';
    }
}
/*
    TODO:
        1) Board class?
        2)
*/


int main(int argc, char* argv[])
{
    srand(time(static_cast<time_t>(0)));
//    Gamer* gamer = Gamer::getGamer(1);
//    SmartGamer *sg = SmartGamer::getGamer(-1);

    Board b;
    MainGame mg;
    size_t turn = 0;
    for(; turn < 9 && mg.run(); ++turn) {
           if(turn % 2 == 0)
           {
               mg.firstGamerStep();
               mg.printBoard();
           }
           else {
               mg.secondGamerStep();
               mg.printBoard();
           }
       }
    // mg.printBoard();
    mg.save(mg.saveFileName_,1,mg.winner_, turn);
    return 0;
}
