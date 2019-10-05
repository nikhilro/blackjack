#ifndef HAND_H_
#define HAND_H_

#include "string"
#include "vector"

class Hand {
    public:
        std::vector<std::pair<char, char>> cards;  // [(suit, rank)]
    public:
        Hand(std::pair<char, char> first);
        Hand(std::pair<char, char> first, std::pair<char, char> second);
        Hand(std::vector<std::pair<char, char>> hands);
        static char rank(char value);
        int total();
};

#endif