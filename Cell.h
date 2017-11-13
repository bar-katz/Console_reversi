//
// Created by bar.
//

#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell {
 private:
  char symbol;
  int x, y;
  friend ostream &operator<<(ostream &, const Cell &);
  friend bool operator==(const Cell &, const Cell &);

 public:
  /**
   * Constructor.
   * @param sym
   * @param x
   * @param y
   */
  Cell(char sym = ' ', int x = 0, int y = 0);

  /**
   * Sets cell symbol.
   * @param sym new symbol
   */
  void setSymbol(char sym);

  /**
   * Gets symbol.
   * @return current symbol
   */
  char getSymbol();

  /**
   * get cell X coordinate.
   * @return x coordinate
   */
  int getX();

  /**
   * get cell Y coordinate.
   * @return y coordinate
   */
  int getY();

};

#endif
