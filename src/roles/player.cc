#include "player.h"

using namespace std;

void Player::playImpl(istream& sin, ostream& sout) {
    // pass
}

int Player::bet(istream& sin, ostream& sout) {
    sout << "How much would you like to bet?" << endl;
    sin >> betSize;
    return betSize;
}

Player::Player(shared_ptr<Dealer> dealer, int order): dealer{dealer}, order{order} {
    dealer->attach(this);
}

Player::~Player() {
    dealer->detach(this);
}

void Player::notify() {
    auto map = dealer->state;
    hand = map[to_string(order)];
}

int Player::bet(istream& sin, ostream& sout) {
    return betImpl(sin, sout);
}