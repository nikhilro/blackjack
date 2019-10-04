#include "blackjack.h"
#include "../roles/dealer.h"
#include "../roles/player.h"

using namespace std;

void Blackjack::placeBets(istream& sin, ostream& sout) {
    for (auto& player : players) {
        bets.emplace_back(player->bet(sin, sout));
    }
}

void Blackjack::playImpl(istream& sin, ostream& sout) {
    if (bets.size == 0) {
        placeBets(sin, sout);
    } else {
        dealer->play(sin, sout); // deal
        for (auto& player : players) {
            while (!player->isDone()) {
                player->play(sin, sout); // play
                string curPlay = player->currentPlay();
                if (curPlay != "")
                dealer->deal(, i);
            }
        }
        dealer->nextRound();
        while (!dealer->isDone()) {
            dealer->play(sin, sout);
        }
        done = true;
    }
}

Blackjack::Blackjack(int num): numPlayers{num} {
    while (--num) {
        players.emplace_back(make_unique<Player>(dealer));
    }
    dealer->setNumPlayers(numPlayers);
}