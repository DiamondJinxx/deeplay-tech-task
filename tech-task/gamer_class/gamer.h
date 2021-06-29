#ifndef GAMER_H
#define GAMER_H
#include "abstract_gamer.h"

class Gamer : public AbstractGamer{
protected:
    Gamer(int symb)
    {
        m_symbol = symb;
        //std::cout << "New gamer object! Symbol is " << m_symbol << '\n';
    }
    static Gamer* singl_ ;//= nullptr;
public:
    virtual ~Gamer();

    //lock copy constructor and operator=
    Gamer(Gamer& other) = delete;
    Gamer& operator=(Gamer& other) = delete;

    static Gamer* getGamer(int c); // static function for getting instance object
    virtual bool nextStep(Board&) override;
};



#endif
