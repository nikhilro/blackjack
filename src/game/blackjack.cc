#include "blackjack.h"

#include "algorithm"

#include "../constants.h"
#include "../roles/dealer.h"
#include "../roles/player.h"

using namespace std;

void Blackjack::playImpl(istream& sin, ostream& sout) {
    if (bets.size == 0) {
        placeBets(sin, sout);
    } else {
        dealer->play(sin, sout); // deal
        for (auto& player : players) {
            while (!player->isDone()) {
                player->play(sin, sout); // play
                pair<int, char> play = player->status();
                if (dealer->respond(player->ordering, play, sout)) { // valid play
                    respond(player->ordering, play, sout);
                }
            }
        }
        while (!dealer->isDone()) {
            dealer->play(sin, sout);
        }
        evaluate();
        printBets(sout);
        printWinnings(sout);
        done = true;
    }
}

void Blackjack::placeBets(istream& sin, ostream& sout) {
    for (auto& player : players) {
        bets.emplace_back(player->bet(sin, sout));
    }
    printBets(sout);
}

void Blackjack::respond(int player, pair<int, char> play, ostream& sout) {
    switch (play.second) {
        case HIT:
        case STAND:
            return;
        case SURRENDER:
            winnings[player] = bets[player] / 2;
            return;
        case SPLIT:
        case DOUBLE:
            bets[player] *= 2; 
            printBets(sout);
            return; 
        default:
            sout << "This should never happen";
            break;
    }
} 

void Blackjack::printHelper(ostream& sout, const vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        sout << "Player " << i << ": " << vec[i] << endl;
    }
}

void Blackjack::printBets(ostream& sout) {
    sout << "Bets are:" << endl;
    printHelper(sout, winnings);
}

void Blackjack::printWinnings(ostream& sout) {
    sout << "Winnings are:" << endl;
    printHelper(sout, winnings);
}

void Blackjack::evaluate() {
    auto& state = dealer->state;
    int dealerTotal = state[to_string(DEALER)].front().total();
    if (dealerTotal > 21) {
        for (int i = 0; i < numPlayers; ++i) {
            for (auto& hand: state[to_string(i)]) {
                if (hand.total() <= 21) {
                    winnings[i] = 2 * bets[i];
                    break;
                }
            }
        }
    } else if (dealerTotal == 21) {
        for (int i = 0; i < numPlayers; ++i) {
            for (auto& hand: state[to_string(i)]) {
                if (hand.total() == 21) {
                    winnings[i] = bets[i];
                    break;
                }
            }
        }
    } else if (dealerTotal < 21) {
        for (int i = 0; i < numPlayers; ++i) {
            vector<int> playerWinnings;
            for (auto& hand: state[to_string(i)]) {
                int handTotal = hand.total();
                if (handTotal == 21) {
                    playerWinnings.emplace_back(2.5 * (float) bets[i]);
                } else if (handTotal > dealerTotal) {
                    playerWinnings.emplace_back(2 * bets[i]);
                } else if (handTotal == dealerTotal) {
                    playerWinnings.emplace_back(bets[i]);
                }
            }
            if (!playerWinnings.empty()) {
                int m = playerWinnings[0];
                for (int i = 1; i < playerWinnings.size(); ++i) {
                    m = max(m, playerWinnings[i]);
                }
                winnings[i] = m;
            }
        }
    }

}

Blackjack::Blackjack(int num): numPlayers{num}, dealer{make_shared<Dealer>(num)} {
    while (--num) {
        players.emplace_back(make_unique<Player>(dealer));
        winnings.emplace_back(0);
    }
}