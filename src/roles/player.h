#ifndef PLAYER_H_
#define PLAYER_H_

#include "unordered_map"
#include "memory"

#include "abstractRole.h"
#include "dealer.h"
#include "../utility/observer.h"

class Player: public AbstractRole, public Observer {
        int order;
        std::shared_ptr<Dealer> dealer;
        void playImpl(std::istream& sin, std::ostream& sout) override;
    public:
        void notify() override;
        Player(std::shared_ptr<Dealer> dealer, int order);
        ~Player();
};

#endif