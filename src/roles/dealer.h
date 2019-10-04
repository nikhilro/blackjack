#ifndef DEALER_H_
#define DEALER_H_

#include "unordered_map"

#include "abstractRole.h"
#include "../utility/subject.h"
#include "../models/hand.h"

class Dealer : public AbstractRole, public Subject {
        std::vector<std::pair<char, char>> deck;
        int numPlayers = 0;
        void deal(std::istream& sin, std::ostream& sout);
        std::pair<char, char> pull();
        void playImpl(std::istream& sin, std::ostream& sout) override;
    public:
        Dealer(int numPlayers);
        std::unordered_map<std::string, std::vector<Hand>> state;
};

#endif