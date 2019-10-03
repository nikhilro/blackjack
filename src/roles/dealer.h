#ifndef DEALER_H_
#define DEALER_H_

#include "unordered_map"

#include "abstractRole.h"
#include "../utility/subject.h"
#include "../models/hand.h"

class Dealer : public AbstractRole, public Subject {
        void playImpl(std::istream& sin, std::ostream& sout) override;
    public:
        std::unordered_map<std::string, Hand> state;
};

#endif