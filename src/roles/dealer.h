#ifndef DEALER_H_
#define DEALER_H_

#include "unordered_map"

#include "abstractRole.h"
#include "../utility/subject.h"
#include "../models/hand.h"

class Dealer : public AbstractRole, public Subject {
    std::unordered_map<std::string, Hand> state;
    void playImpl(std::istream& sin, std::ostream& sout);
};

#endif