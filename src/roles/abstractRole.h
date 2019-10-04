#ifndef ABSTRACT_ROLE_H_
#define ABSTRACT_ROLE_H_

#include "iostream"
#include "utility"
#include "vector"

#include "../models/hand.h"

class AbstractRole {
    protected:
        std::vector<Hand> hands;
        bool done = false;
        virtual void playImpl(std::istream& sin, std::ostream& sout) = 0;
    public:
        bool isDone();
        void nextRound();
        void play(std::istream& sin, std::ostream& sout);
        virtual ~AbstractRole() = default;
};

#endif