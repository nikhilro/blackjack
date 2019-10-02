#include "abstractRole.h"

using namespace std;

void AbstractRole::play(istream& sin, ostream& sout) {
    playImpl(sin, sout);
}

bool AbstractRole::isDone() {
    return done;
}