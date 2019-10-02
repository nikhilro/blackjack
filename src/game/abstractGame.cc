#include "abstractGame.h"

using namespace std;

void AbstractGame::play(istream& sin, ostream& sout) {
    playImpl(sin, sout);
}

bool AbstractGame::isDone() {
    return done;
}