#include "dealer.h"

#include "algorithm"

#include "../constants.h"

using namespace std;

pair<char, char> Dealer::pull() {
    auto card = deck.back();
    deck.pop_back();
    return card;
}

void Dealer::deal(istream& sin, ostream& sout) {
    state[DEALER] = vector<Hand>({pull()})
    for (int i = 0; i < numPlayers; ++i) {

    }
}

void Dealer::playImpl(istream& sin, ostream& sout) {
    if (state.empty) {
        deal(sin, sout);
    }
}

Dealer::Dealer(int num): numPlayers{num} {
    vector<char> suits{HEARTS, DIAMONDS, SPADES, CLUBS};
    vector<char> ranks{ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, 
        NINE, TEN, JACK, QUEEN, KING};
    
    for (int i = 0; i < suits.size(); ++i) {
        for (int j = 0; j < ranks.size(); ++j) {
            deck.emplace_back(pair{suits[i], ranks[j]});
        }
    }

    random_shuffle(deck.begin(), deck.end());
}