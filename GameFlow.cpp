//
// Created by bar.
//

#include "GameFlow.h"

GameFlow::GameFlow(Player &p1, Player &p2) : game(p1, p2) {

  this->game_state = 0;

}

void GameFlow::run() {
  while (this->game_state != END_GAME) {
    switch (this->game_state) {
      case 0: {
        this->game.start();
        this->game_state++;
        break;
      }
      case 1: {
        if (this->game.x_cells_count() > this->game.o_cells_count()) {
          cout << "X player has won!" << endl;
        } else if (this->game.o_cells_count() > this->game.x_cells_count()) {
          cout << "O player has won!" << endl;
        } else {
          cout << "it's a tie." << endl;
        }
        this->game_state++;
        break;
      }
    }
  }
}