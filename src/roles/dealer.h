#ifndef DEALER_H_
#define DEALER_H_

#include "map"

#include "abstractRole.h"
#include "../utility/subject.h"
#include "../models/hand.h"

class Dealer : public AbstractRole, public Subject {
        std::vector<std::pair<char, char>> deck;
        int numPlayers = 0;
        void printState(std::ostream& sout);
        std::pair<char, char> pull();
        void deal(std::istream& sin, std::ostream& sout);
        void playImpl(std::istream& sin, std::ostream& sout) override;
        static bool isEqualRank(const Hand& hand);
        bool respondImpl(int player, std::pair<int, char> play, std::ostream& sout);
        bool approveImpl(int player);
    public:
        std::map<std::string, std::vector<Hand>> state;
        Dealer(int numPlayers);
        bool respond(int player, std::pair<int, char> play, std::ostream& sout);
        bool approve(int player);
};

#endif