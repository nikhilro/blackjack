#include "hand.h"

#include "../constants.h"

#include "iostream"

using namespace std;

Hand::Hand(pair<char, char> first): cards{first} {}

Hand::Hand(pair<char, char> first, pair<char, char> second): cards{first, second} {}

Hand::Hand(vector<pair<char, char>> hands): cards{hands} {}

char Hand::rank(char value) {
    if ((int) value <= 9) {
        return value;
    } else {
        return 10;
    }
}

int Hand::total() {
    int total = 0, numOfAces = 0;
    for (int i = 0; i < cards.size(); ++i) {
        numOfAces += cards[i].second == ACE ? 1 : 0;
        total += (int) rank(cards[i].second);
    }
    while (total <= 11 && numOfAces--) {
        total += 10;
    }
    return total;
}
