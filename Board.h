#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Cell.h"

#define X 'X'
#define O 'O'
#define BLANK ' '

using namespace std;

class Board {
 private:
  vector<vector<Cell> > cells;
  int size;

 public:
  /**
   * Constructor.
   * @param col Number of columns
   * @param row Number of rows
   */
  Board(int col = 8, int row = 8);

  /**
   * Gets the (i, j) cell.
   * @param i i coordinate
   * @param j j coordinate
   * @return
   */
  Cell getCell(int i, int j) { return this->cells[i][j]; }

  /**
   * Sets a symbol for the (i, j) cell.
   * @param sym New symbol
   * @param i i coordinate
   * @param j j coordinate
   */
  void setCellSymbol(char sym,
                     int i,
                     int j) { this->cells[i][j].setSymbol(sym); }

  /**
   * Size of board.
   * @return size
   */
  int getSize() { return this->size; }

  /**
   * Draws board.
   */
  void draw();

};

#endif