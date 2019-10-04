#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include "iostream"

#include "abstractGame.h"
#include "../roles/dealer.h"
#include "../roles/player.h"

class Blackjack : public AbstractGame {
        std::shared_ptr<Dealer> dealer;
        std::vector<std::unique_ptr<Player>> players;
        std::vector<int> bets;
        int numPlayers;
        void playImpl(std::istream& sin, std::ostream& sout) override;
        void placeBets(std::istream&, std::ostream& sout);
    public:
        Blackjack(int numPlayers);
};

#endif