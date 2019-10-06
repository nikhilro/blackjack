#include "dealer.h"

#include "algorithm"

#include "../constants.h"

using namespace std;

void printHands(ostream& sout, vector<Hand> hands) {
    for (auto& hand: hands) {
        for (int i = 0; i < hand.cards.size(); ++i) {
            sout << i << ": " << hand.cards[i].first << hand.cards[i].second << " ";
        }
    }
}

void Dealer::printState(ostream& sout) {
    for (auto& hands: state) {
        if (hands.first == to_string(DEALER)) {
            sout << "Dealer cards are:" << endl;
        } else {
            sout << "Player " << hands.first << "cards are:" << endl;
        }
        printHands(sout, hands.second);
    }
}

pair<char, char> Dealer::pull() {
    auto card = deck.back();
    deck.pop_back();
    return card;
}

void Dealer::deal(istream& sin, ostream& sout) {
    state[to_string(DEALER)] = vector<Hand>({pull()});
    for (int i = 0; i < numPlayers; ++i) {
        state[to_string(i)] = vector<Hand>({pull(), pull()});
    }

    hands = state[to_string(DEALER)];
    notifyAllObservers();
    printState(sout);
}

void Dealer::playImpl(istream& sin, ostream& sout) {
    if (state.empty()) {
        deal(sin, sout);
    } else {
        state[to_string(DEALER)].emplace_back(pull());
        hands = state[to_string(DEALER)];
        int total = hands.front().total();
        done = total >= 17;
    }
}

bool Dealer::isEqualRank(const Hand& hand) {
    return hand.rank(hand.cards[0].second) == hand.rank(hand.cards[1].second);
}

bool Dealer::respondImpl(int player, std::pair<int, char> play, std::ostream& sout) {
    bool valid = true, print = false;
    switch (play.second) {
        case HIT:
        case DOUBLE:
            if (state[to_string(player)][play.first].total() < 21) {
                state[to_string(player)][play.first].cards.emplace_back(pull());
                print = true;
            } else {
                valid = false;
            }
            break;
        case STAND:
        case SURRENDER:
            valid = state[to_string(player)][play.first].cards.size() <= 2;
            break;
        case SPLIT:
            auto& hand = state[to_string(player)][play.first];
            if (hand.cards.size() == 2 && isEqualRank(hand)) {
                state[to_string(player)] = vector<Hand>{{hand.cards[0], pull()}, {hand.cards[1], pull()}};
            } else {
                valid = false;
            }
            print = true;
            break;
        // default:
        //     valid = false;
        //     break;
    }
    if (!valid) {
        sout << "Invalid Play: " << play.second << "." << endl;
    } else if (print) {
        notifyAllObservers();
        printState(sout);
    }
    return valid;
}

Dealer::Dealer(int num): numPlayers{num} {
    vector<char> suits{HEARTS, DIAMONDS, SPADES, CLUBS};
    vector<char> ranks{ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, 
        NINE, TEN, JACK, QUEEN, KING};
    
    for (int i = 0; i < suits.size(); ++i) {
        for (int j = 0; j < ranks.size(); ++j) {
            deck.emplace_back(pair<char, char>{suits[i], ranks[j]});
        }
    }

    random_shuffle(deck.begin(), deck.end());
}

bool Dealer::respond(int player, std::pair<int, char> play, std::ostream& sout) {
    return respondImpl(player, play, sout);
}