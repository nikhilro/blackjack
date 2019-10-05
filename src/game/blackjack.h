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
        std::vector<int> winnings;
        int numPlayers;
        void playImpl(std::istream& sin, std::ostream& sout) override;
        void placeBets(std::istream&, std::ostream& sout);
        void respond(int player, std::pair<int, char> play, std::ostream& sout);
        void printHelper(std::ostream& sout, const std::vector<int>& vec);
        void printBets(std::ostream& sout);
        void printWinnings(std::ostream& sout);
        void evaluate(); 
    public:
        Blackjack(int numPlayers);
};

#endif