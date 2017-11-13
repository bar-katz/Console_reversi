//
// Created by bar.
//

#include "HumanPlayer.h"

Cell HumanPlayer::makeMove(vector<Cell> avMoves) {

  int x, y;
  bool found = false;

  cout << "Your Possible moves: ";
  Player::printMoves(avMoves);
  cout << endl << endl;

  for (;;) {
    cout << "Please enter your move row,col:";
    cin >> x >> y;

    // translate for computing
    x -= 1;
    y -= 1;

    for (int i = 0; i < avMoves.size(); i++) {
      if (x >= 0 && y >= 0 && x == avMoves[i].getX() && y == avMoves[i].getY
          ()) {
        found = true;
        break;
      }
    }

    // found in avMoves
    if (found) {
      break;
    } else {
      cout << "Not a valid move. Try again." << endl;
    }
  }

  return Cell(this->getSymbol(), x, y);
}