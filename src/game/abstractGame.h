#ifndef ABSTRACT_GAME_H_
#define ABSTRACT_GAME_H_

#include "iostream"

class AbstractGame {
    protected:
        bool done = false;
        virtual void playImpl(std::istream& sin, std::ostream& sout) = 0;
    public:
        bool isDone();
        void play(std::istream& sin, std::ostream& sout);
        virtual ~AbstractGame() = default;
};

#endif