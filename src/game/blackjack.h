#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include "iostream"

#include "abstractGame.h"
#include "../roles/dealer.h"

class Blackjack : public AbstractGame {
        std::shared_ptr<Dealer> dealer;
        void playImpl(std::istream& sin, std::ostream& sout) override;
    public:
        Blackjack(int numOfPlayers);
};

#endif