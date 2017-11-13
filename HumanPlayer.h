//
// Created by bar.
//

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
 public:
  /**
   * Constructor.
   * @param sym player's symbol
   */
  HumanPlayer(char sym) : Player(sym) {}

  /**
   * Is player a human or computer.
   * @return true if human, otherwise false
   */
  virtual bool isHuman() { return true; }

  /**
   * Make a move.
   * @param avMoves all available moves for this player.
   * @return player's choice
   */
  virtual Cell makeMove(vector<Cell>);
};

#endif
