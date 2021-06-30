#include "abstract_gamer.h"

int AbstractGamer:: getSymbol()
{
    return m_symbol;
}

bool AbstractGamer::win(Board& b)
{
    bool r1 = (b.map.at(0) == m_symbol) && (b.map.at(1) == m_symbol) && (b.map.at(2) == m_symbol);
    bool r2 = (b.map.at(3) == m_symbol) && (b.map.at(4) == m_symbol) && (b.map.at(5) == m_symbol);
    bool r3 = (b.map.at(6) == m_symbol) && (b.map.at(7) == m_symbol) && (b.map.at(8) == m_symbol);

    bool c1 = (b.map.at(0) == m_symbol) && (b.map.at(3) == m_symbol) && (b.map.at(6) == m_symbol);
    bool c2 = (b.map.at(1) == m_symbol) && (b.map.at(4) == m_symbol) && (b.map.at(7) == m_symbol);
    bool c3 = (b.map.at(2) == m_symbol) && (b.map.at(5) == m_symbol) && (b.map.at(8) == m_symbol);

    bool d1 = (b.map.at(0) == m_symbol) && (b.map.at(4) == m_symbol) && (b.map.at(8) == m_symbol);
    bool d2 = (b.map.at(2) == m_symbol) && (b.map.at(4) == m_symbol) && (b.map.at(6) == m_symbol);
    bool result = (r1 || r2 || r3 || c1 || c2 || c3 || d1 || d2);
   // std::cout << "gamer " << b.gridSymbol(m_symbol) << " winning? " << (result ? "Yes" : "No") << std::endl;
    //result == true ? (winner_ = m_symbol):(winner_ = 0);
    return result;
}
