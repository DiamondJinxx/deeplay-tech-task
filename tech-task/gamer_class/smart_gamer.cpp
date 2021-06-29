#include "smart_gamer.h"

// return instance object of Gamer
SmartGamer* SmartGamer::singl_ = nullptr;
SmartGamer* SmartGamer::getGamer(int s)
{
    if(singl_ == nullptr)
        singl_ = new SmartGamer(s);
    return singl_;
}

bool SmartGamer::nextStep(Board& b)
{
   // map.at(0).at(0) = m_symbol;
    std::vector<int> ec = b.emptyCells();
    if(ec.size() != 0)
    {
        int r = rand() % (ec.size());
        //std::cout << m_symbol << std::endl;
        b.map.at(ec.at(r)) = m_symbol;
        return true;
    }
    else
        return false;
}

SmartGamer::~SmartGamer()
{
    if(singl_)
        delete singl_;
}
