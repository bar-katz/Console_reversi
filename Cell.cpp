//
// Created by bar.
//

#include "Cell.h"

Cell::Cell(char sym, int x, int y) : symbol(sym), x(x), y(y) {}

void Cell::setSymbol(char sym) { this->symbol = sym; }

char Cell::getSymbol() { return this->symbol; }

int Cell::getX() { return this->x; }

int Cell::getY() { return this->y; }

bool operator==(const Cell &c1, const Cell &c2) {
  return (c1.x == c2.x) && (c1.y == c2.y);
}

ostream &operator<<(ostream &strm, const Cell &c) {
  return strm << "(" << c.x + 1 << "," << c.y + 1 << ")";
}