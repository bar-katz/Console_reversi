//
// Created by bar.
//

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdio>
#include "Cell.h"
#include "Board.h"
#include "Player.h"

#define UPDATE 'u'
#define POSSIBLE_MOVES 'p'

using namespace std;

class Game {
 private:
  Board board;
  Player &player1;
  Player &player2;

  // Number of cells for each player
  int xCells, oCells;

  // How many moves to end of the game
  int moves;

  // In charge of which player plays
  int whos_turn;

  /**
   * Play a turn for one player.
   * Player - the player
   */
  void playerTurn(Player &);

  /**
   * Searches around (row, col) and adds specific cells to addTo -
   * functionality differs according to given settings:
   * p - Possible moves
   * u - Update call
   *
   * @param row row coordinate
   * @param col col coordinate
   * @param player the player that has the turn
   * @param addTo vector to add Cells to
   * @param whereFrom from where the call was made
   */
  void searchAround(int row, int col, char player, vector<Cell> &addTo, char
  whereFrom);

 public:
  /**
   * Constructor.
   * @param p1 player 1
   * @param p2 player 2
   */
  Game(Player &p1, Player &p2);

  /**
   * Starts a game.
   */
  void start();

  /**
   * Plays one round - one turn for each player(see void playerTurn(Player &)).
   */
  void playOneTurn();

  /**
   * Gets an empty vector and fills it with the available cells to make a move
   * for a given symbol\ char.
   * @param avMoves empty vector
   * @param player player's symbol
   */
  void getPossibleMoves(vector<Cell> &avMoves, char player);

  /**
   * Gets number of X cells.
   * @return number of X cells
   */
  int x_cells_count() {
    return this->xCells;
  }

  /**
   * Gets number of O cells.
   * @return number of O cells
   */
  int o_cells_count() {
    return this->oCells;
  }

  /**
   * Updates the board.
   * @param playerMove the latest move of a player
   */
  void update(Cell &playerMove);

};
#endif
