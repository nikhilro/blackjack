#ifndef PLAYER_H_
#define PLAYER_H_

#include "memory"

#include "abstractRole.h"
#include "dealer.h"
#include "../utility/observer.h"

class Player: public AbstractRole, public Observer {
        int order;
        int betSize;
        char currentPlay;
        int currentHand;
        std::shared_ptr<Dealer> dealer;
        void playImpl(std::istream& sin, std::ostream& sout) override;
        int betImpl(std::istream&, std::ostream&);
    public:
        Player(std::shared_ptr<Dealer> dealer, int order);
        ~Player();
        void notify() override;
        int bet(std::istream&, std::ostream&);
        std::pair<int, char> status();
        int ordering();
};

#endif