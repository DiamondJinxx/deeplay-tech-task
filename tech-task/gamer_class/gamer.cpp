#include "gamer.h"

// return instance object of Gamer
Gamer* Gamer::singl_ = nullptr;
Gamer* Gamer::getGamer(int s)
{
    if(singl_ == nullptr)
        singl_ = new Gamer(s);
    return singl_;
}

bool Gamer::nextStep(Board& b)
{
   // map.at(0).at(0) = m_symbol;
    std::vector<int> ec = b.emptyCells();
    if(ec.size() != 0)
    {
        int r = rand() % (ec.size());
        //Gamer::cell ce = ec.at(r);
        //std::cout << m_symbol << std::endl;
        b.map.at(ec.at(r)) = m_symbol;
        return true;
    }
    else
        return false;

}

Gamer::~Gamer()
{
    if(singl_)
        delete singl_;
}
