#include "maingame.h"

MainGame::MainGame()
{
    g_ = Gamer::getGamer(-1);
    sg_ = SmartGamer::getGamer(1);
    b_.clear();
    saveFileName_ = "game_data.csv";
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
    int cell = getBestCell(sg_->getSymbol());
   // std::cout << "Choose cell: " << cell << std::endl;
    sg_->setBestStep(b_, cell);
}

void MainGame::secondGamerStep()
{

    g_->nextStep(b_);
}

bool MainGame::win(Board& b,int gamerSymbol) // check win of gamer
{
    bool r1 = (b.map.at(0) == gamerSymbol) && (b.map.at(1) == gamerSymbol) && (b.map.at(2) == gamerSymbol);
    bool r2 = (b.map.at(3) == gamerSymbol) && (b.map.at(4) == gamerSymbol) && (b.map.at(5) == gamerSymbol);
    bool r3 = (b.map.at(6) == gamerSymbol) && (b.map.at(7) == gamerSymbol) && (b.map.at(8) == gamerSymbol);

    bool c1 = (b.map.at(0) == gamerSymbol) && (b.map.at(3) == gamerSymbol) && (b.map.at(6) == gamerSymbol);
    bool c2 = (b.map.at(1) == gamerSymbol) && (b.map.at(4) == gamerSymbol) && (b.map.at(7) == gamerSymbol);
    bool c3 = (b.map.at(2) == gamerSymbol) && (b.map.at(5) == gamerSymbol) && (b.map.at(8) == gamerSymbol);

    bool d1 = (b.map.at(0) == gamerSymbol) && (b.map.at(4) == gamerSymbol) && (b.map.at(8) == gamerSymbol);
    bool d2 = (b.map.at(2) == gamerSymbol) && (b.map.at(4) == gamerSymbol) && (b.map.at(6) == gamerSymbol);
    bool result = (r1 || r2 || r3 || c1 || c2 || c3 || d1 || d2);
   // std::cout << "gamer " << b.gridSymbol(gamerSymbol) << " winning? " << (result ? "Yes" : "No") << std::endl;
    result == true ? (winner_ = gamerSymbol):(winner_ = 0);
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
    std::cout << '\n';
    b_.print();
}

bool MainGame::run()
{
    return (!gameover() && !win(b_, g_->getSymbol()) && !win(b_, sg_->getSymbol()));
}

int MainGame::minimax(Board& b, int gamer)
{
    //How is the position like for player (their turn) on board?
    bool wg = win(b, g_->getSymbol());
    bool wsg = win(b, sg_->getSymbol());
    if(wg)
        return -1;
    if(wsg)
        return 1;
    if(b.isFull())
        return 0;

    //b.print();
    int move = -1;
    int score = -2;//Losing moves are preferred to no move
    size_t i;
    std::vector<int> ec = b.emptyCells();
    size_t s = ec.size();
    //std::cout << "Size of epmty cells: " << s << std::endl;
    for(i = 0; i < s; ++i) //For all empty moves,
    {
        b.map.at(ec.at(i))  = gamer;//move
        int thisScore = minimax(b, -1 * gamer);// we know that smart_gamer_symb = -1 * gamer_symb
        if(thisScore > score) {
            score = thisScore;
            move = i;
        }
        b.map.at(ec.at(i)) = 0;//Back state of board after move
    }
    if(move == -1) return 0;
    return score;
}

int MainGame::minimax2(Board& b, int gamer)
{
    //How is the position like for player (their turn) on board?
    bool wg = win(b, g_->getSymbol());
    bool wsg = win(b, sg_->getSymbol());
    if(wg)
        return -1;
    if(wsg)
        return 1;
    if(b.isFull())
        return 0;

    //b.print();
    int move = -1;
    int score = 0;//Losing moves are preferred to no move
    size_t i;
    std::vector<int> ec = b.emptyCells();
    size_t s = ec.size();

    if(gamer == sg_->getSymbol())
    {
        for(i = 0; i < s; ++i)
        {
            b.map.at(ec.at(i)) = gamer;
            int ts = minimax2(b, -1 * gamer);
            b.map.at(ec.at(i)) = 0;
            if(ts > score)
            {
                score = ts;
                move = ec.at(i);
            }
        }
        return score;
    }
    if(gamer == g_->getSymbol())
    {
        for(i = 0; i < s; ++i)
        {
            b.map.at(ec.at(i)) = gamer;
            int ts = minimax2(b, -1 * gamer);
            b.map.at(ec.at(i)) = 0;
            if(ts < score)
            {
                score = ts;
                move = ec.at(i);
            }
        }
        return score;
    }
}

int MainGame::getBestCell(int gamer)
{
    std::vector<int> ec = b_.emptyCells();
    size_t s = ec.size();
    int move = -1;
    int score = -2;
    for(size_t i = 0; i < s; ++i)
    {
        b_.map.at(ec.at(i)) = gamer;
//        int ts = minimax(b_, gamer);
        int ts = minimax2(b_, gamer);
        if(ts > score)
        {
            score = ts;
            move = i;
        }
       b_.map.at(ec.at(i)) = 0;
    }
    return ec.at(move);
}

bool MainGame::save(std::string fn, int part_number, int winner, int steps)
{
    bool result;
    std::ofstream outf(fn, std::ios::app);
    if(!outf.is_open())
    {
        std::cerr << "Can't open file. Cancel operation\n";
        result =  false;
    }
    else
    {
        outf << part_number << ";";
        for(auto n : b_.map)
            outf << n << ";";
        outf << winner << ";" << steps << "\n";
        result = true;
    }
    return result;
}
