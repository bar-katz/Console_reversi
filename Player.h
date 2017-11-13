//
// Created by bar.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Cell.h"

class Player {
 private:
  char symbol;

 public:
  /**
   * Constructor.
   * @param sym player's symbol
   */
  Player(char sym) : symbol(sym) {}

  /**
   * Gets player's symbol.
   * @return player's symbol
   */
  char getSymbol() { return this->symbol; }

  /**
   * Is player a human or computer.
   * @return true if human, otherwise false
   */
  virtual bool isHuman() { return false; }

  /**
   * Make a move.
   * @param avMoves all available moves for this player.
   * @return player's choice
   */
  virtual Cell makeMove(vector<Cell> avMoves) {}

  /**
   * Prints all available moves for this player.
   * @param avMoves all available moves for this player
   */
  static void printMoves(vector<Cell> avMoves);

};

#endif
