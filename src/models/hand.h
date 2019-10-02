#ifndef HAND_H_
#define HAND_H_

#include "vector"
#include "string"

class Hand {
    public:
        std::vector<std::pair<std::string, std::string>> data;  // [(suit, rank), (suit, rank)...]
};

#endif