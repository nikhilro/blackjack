#ifndef HAND_H_
#define HAND_H_

#include "string"

class Hand {
    public:
        std::pair<char, char> first;  // [(suit, rank)]
        std::pair<char, char> second;
    public:
        Hand(std::pair<char, char> first): first{first} {}
        Hand(std::pair<char, char> first, std::pair<char, char> second): first{first}, second{second} {}
};

#endif