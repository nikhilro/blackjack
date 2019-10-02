#ifndef ABSTRACT_GAME_H_
#define ABSTRACT_GAME_H_

#include "iostream"
#include "vector"
#include "memory"

#include "../roles/abstractRole.h"

class AbstractGame {
    protected:
        bool done = false;
        std::vector<std::unique_ptr<AbstractRole>> participants;
        virtual void playImpl(std::istream& sin, std::ostream& sout) = 0;
    public:
        bool isDone();
        void play(std::istream& sin, std::ostream& sout);
        virtual ~AbstractGame() = default;
};

#endif