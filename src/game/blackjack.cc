#include "blackjack.h"
#include "../roles/dealer.h"
#include "../roles/player.h"

using namespace std;

void Blackjack::playImpl(istream& sin, ostream& sout) {
    dealer->nextRound();
    for (auto& player : participants) {
        player->nextRound();
    }

    while (!dealer->isDone()) {
        dealer->play(sin, sout);
    }
    for (auto& player : participants) {
        while (!player->isDone()) {
            player->play(sin, sout);
        }
    }

    done = dealer->isGameOver();
}

Blackjack::Blackjack(int num) {
    while (--num) {
        participants.emplace_back(make_unique<Player>(dealer));
    }
}