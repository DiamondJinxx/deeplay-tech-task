#ifndef SMARTGAMER_H
#define SMARTGAMER_H
#include "abstract_gamer.h"

class SmartGamer : public AbstractGamer{
protected:
    SmartGamer(int symb)
    {
        m_symbol = symb;
        std::cout << "New gamer object! Symbol is " << m_symbol << '\n';
    }
    static SmartGamer* singl_ ;//= nullptr;
public:
    virtual ~SmartGamer();

    //lock copy constructor and operator=
    SmartGamer(SmartGamer& other) = delete;
    SmartGamer& operator=(SmartGamer& other) = delete;

    static SmartGamer* getGamer(int c); // static function for getting instance object
    virtual  bool nextStep(Board&) override;
};



#endif
