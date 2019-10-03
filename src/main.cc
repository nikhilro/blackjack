#include <iostream>

#include "game/blackjack.h"

using namespace std;

int main() {
  bool nextGame = true;
  while (nextGame) {
    int num = 0;
    cout << "Please enter the number of players:" << endl;
    cin >> num;

    Blackjack game(num);
    while (!game.isDone()) {
      game.play(cin, cout);
    }

    char type;
    cout << "Would you like to play another game? [y/n]" << endl;
    cin >> type;
    nextGame = type == 'y';
  }
  
  return 0;
}
