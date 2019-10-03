#include "player.h"

using namespace std;

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