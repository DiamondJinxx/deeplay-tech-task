#include "maingame.h"

MainGame::MainGame()
{
    g_ = Gamer::getGamer(1);
    sg_ = SmartGamer::getGamer(-1);
    b_.clear();
}

void MainGame::step() // one step of game
{
    int steps = 0;
    bool g1, g2;
    while(steps < 9)
    {
        std::cout << "step: " << steps + 1 << std::endl;
        ++steps;


        std::cout << "-----------------\n";
        //printMap(map);
        b_.print();
        std::cout << "-----------------\n";

        std::cout << "step: " << steps + 1<< std::endl;

        //printMap(map);
        b_.print();
        std::cout << "-----------------\n";
        ++steps;
    }
}
void MainGame::firstGamerStep()
{
    g_->nextStep(b_);
}

void MainGame::secondGamerStep()
{
    sg_->nextStep(b_);
}

bool MainGame::win(int gamerSymbol) // check win of gamer
{
    bool r1 = (b_.map.at(0) == gamerSymbol) && (b_.map.at(1) == gamerSymbol) && (b_.map.at(2) == gamerSymbol);
    bool r2 = (b_.map.at(3) == gamerSymbol) && (b_.map.at(4) == gamerSymbol) && (b_.map.at(5) == gamerSymbol);
    bool r3 = (b_.map.at(6) == gamerSymbol) && (b_.map.at(7) == gamerSymbol) && (b_.map.at(8) == gamerSymbol);

    bool c1 = (b_.map.at(0) == gamerSymbol) && (b_.map.at(3) == gamerSymbol) && (b_.map.at(6) == gamerSymbol);
    bool c2 = (b_.map.at(1) == gamerSymbol) && (b_.map.at(4) == gamerSymbol) && (b_.map.at(7) == gamerSymbol);
    bool c3 = (b_.map.at(2) == gamerSymbol) && (b_.map.at(5) == gamerSymbol) && (b_.map.at(8) == gamerSymbol);

    bool d1 = (b_.map.at(0) == gamerSymbol) && (b_.map.at(4) == gamerSymbol) && (b_.map.at(8) == gamerSymbol);
    bool d2 = (b_.map.at(2) == gamerSymbol) && (b_.map.at(4) == gamerSymbol) && (b_.map.at(6) == gamerSymbol);
    bool result = (r1 || r2 || r3 || c1 || c2 || c3 || d1 || d2);
    std::cout << "gamer " << gamerSymbol << " winning? " << result << std::endl;
    return result;
}

bool MainGame::gameover()
{
    if(b_.isFull())
        return true;
    return false;
}

void MainGame::printBoard()
{
   // win(g_->getSymbol());
   // win(sg_->getSymbol());
    std::cout << '\n';
    b_.print();
}

bool MainGame::run()
{
    return (!gameover() && !win(g_->getSymbol()) && !win(sg_->getSymbol()));
}
