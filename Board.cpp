
#include "Board.h"

Board::Board(int col, int row) {
  this->size = col;

  this->cells = vector<vector<Cell> >(row, vector<Cell>(col, Cell()));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      this->cells[i][j] = Cell(BLANK, i, j);
  }

  this->cells[row / 2 - 1][col / 2 - 1].setSymbol(O);
  this->cells[row / 2 - 1][col / 2].setSymbol(X);
  this->cells[row / 2][col / 2 - 1].setSymbol(X);
  this->cells[row / 2][col / 2].setSymbol(O);

}

void Board::draw() {

  cout << " | ";
  for (int i = 0; i < this->size; i++) {
    cout << i + 1 << " | ";
  }
  cout << endl;
  cout << "--";

  for (int i = 0; i < this->size; i++) {
    cout << "----";
  }
  cout << endl;

  for (int i = 0; i < this->size; i++) {

    cout << i + 1 << "|";

    for (int j = 0; j < this->size; j++) {
      cout << " " << this->cells[i][j].getSymbol() << " |";
    }
    cout << endl;
    cout << "--";

    for (int j = 0; j < this->size; j++) {
      cout << "----";
    }
    cout << endl;
  }
}
