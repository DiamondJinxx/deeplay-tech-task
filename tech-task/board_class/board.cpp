#include "board.h"

Board::Board() : m_size(9)
{
    for(size_t i = 0; i < m_size; ++i)
    {
        map.push_back(0);
    }
}
void Board::clear()
{
    for(size_t i = 0; i < m_size; ++i)
    {
        map.at(i) = 0;
    }
}

char Board::gridSymbol(int s)
{
    switch (s) {
        case 1:
            return 'X';
        break;
        case -1:
            return 'O';
        break;
        case 0:
            return ' ';
        break;
    }
}

void Board::print()
{

    for(size_t i = 0; i < m_size; i += 3)
    {

        std::cout << "|" << gridSymbol(map.at(i)) << "|" << gridSymbol(map.at(i+1)) << "|" << gridSymbol(map.at(i+2)) <<  '|' << std::endl;
        std::cout << (i == 6 ? "" : "+-+-+-+\n");
    }
}
std::vector<int> Board::emptyCells() const
{
    std::vector<int> ec;
    size_t s = map.size();
    for(size_t i = 0; i < s; ++i)
    {
        if(map.at(i) == 0)
        {
            ec.push_back(i);
        }
    }
    return ec;
}

bool Board::isFull()
{
    if(emptyCells().size() == 0)
        return true;
    return false;
}

Board::~Board()
{

}

