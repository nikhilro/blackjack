#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include "iostream"

#include "abstractGame.h"

class Blackjack : public AbstractGame {
    void playImpl(std::istream& sin, std::ostream& sout) override;
};

#endif