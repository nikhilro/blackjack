#include "player.h"

#include "../constants.h"

using namespace std;

void Player::playImpl(istream& sin, ostream& sout) {
    sout << "Player " << order << "'s turn. ";
    sout << "What would you like to do? ";
    sout << "[hit: " << HIT;
    sout << ", stand: " << STAND;
    sout << ", double: " << DOUBLE;
    sout << ", split: " << SPLIT;
    sout << ", surrender: " << SURRENDER << "]" << endl;
    sin >> currentPlay;
    if (hands.size() > 1 && (currentPlay == HIT || currentPlay == DOUBLE || currentPlay == SPLIT)) {
        sout << "You have " << hands.size() << " hands. Which hand do you want to play on?" << endl;
        sin >> currentHand;
        --currentHand;
    } else {
        currentHand = 0;
    }
    if (currentPlay == STAND || currentPlay == SURRENDER || currentPlay == DOUBLE) {
        done = true;
    }
}

int Player::betImpl(istream& sin, ostream& sout) {
    sout << "Player " << order << ": How much would you like to bet?" << endl;
    sin >> betSize;
    return betSize;
}

Player::Player(shared_ptr<Dealer> dealer, int order): order{order}, dealer{dealer} {
    dealer->attach(this);
}

Player::~Player() {
    dealer->detach(this);
}

void Player::notify() {
    hands = dealer->state[to_string(order)];
}

int Player::bet(istream& sin, ostream& sout) {
    return betImpl(sin, sout);
}

pair<int, char> Player::status() {
    return {currentHand, currentPlay};
}

int Player::ordering() {
    return order;
}