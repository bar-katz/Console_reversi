//
// Created by bar.
//

#ifndef GAMEFLOW_H
#define GAMEFLOW_H

#include "Game.h"
#include "HumanPlayer.h"

#define END_GAME 2

class GameFlow {
 private:
  int game_state;
  Game game;

 public:
  /**
   * Constructor.
   * @param p1 first player
   * @param p2 second player
   */
  GameFlow(Player &p1, Player &p2);

  /**
   * Runs the game stages.
   */
  void run();
};

#endif
