//
// Created by bar.
//

#include "Player.h"

void Player::printMoves(vector<Cell> avMoves) {
  for (int i = 0; i < avMoves.size(); i++) {

    cout << avMoves[i];

    if(i != avMoves.size() - 1) {
      cout << ",";
    }
  }
}