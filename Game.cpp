//
// Created by bar.
//

#include "Game.h"

Game::Game(Player &p1, Player &p2) : board(), player1(p1), player2(p2) {

  this->player1 = p1;
  this->player2 = p2;
  this->xCells = 2;
  this->oCells = 2;
  this->moves = board.getSize() * board.getSize() - 4;
  this->whos_turn = 0;

}

void Game::start() {

  while (this->moves > 0) {

    this->playOneTurn();

  }
}

void Game::playOneTurn() {

  cout << "Current board:" << endl << endl;

  this->board.draw();

  // player1 turn
  if (this->whos_turn % 2 == 0) {
    this->playerTurn(this->player1);
  } else { // player2 turn
    this->playerTurn(this->player2);
  }
  this->whos_turn++;
}

void Game::playerTurn(Player &player) {

  vector<Cell> avMoves;
  Cell playerMove;

  cout << player.getSymbol() << ": It's your move." << endl;

  // get all possible moves for the player
  this->getPossibleMoves(avMoves, player.getSymbol());

  if (avMoves.size() > 0) {
    this->moves--;

    // makeMove makes sure the move is valid
    playerMove = player.makeMove(avMoves);

    if(player.getSymbol() == X) {
      this->xCells++;
    } else {
      this->oCells++;
    }

    // update cell
    this->board.setCellSymbol(player.getSymbol(), playerMove.getX(),
                              playerMove.getY());

    // update board
    this->update(playerMove);

  } else {
    cout << "No possible moves. Play passes back to the other player. Press"
        " any key to continue." << endl;
    if (player.isHuman()) {
      getchar();
    }
  }
}

void Game::update(Cell &playerMove) {

  // player move cell
  int row = playerMove.getX(), col = playerMove.getY();

  vector<Cell> rivals_to_flip;

  this->searchAround(row, col, playerMove.getSymbol(), rivals_to_flip, UPDATE);

}

void Game::getPossibleMoves(vector<Cell> &avMoves, char player) {
  int bSize = this->board.getSize();

  int row = 0, col = 0; // current cell

  for (row = 0; row < bSize; row++) {
    for (col = 0; col < bSize; col++) {

      // not a blank cell
      if (this->board.getCell(row, col).getSymbol() != BLANK) {
        continue;
      }

      this->searchAround(row, col, player, avMoves, POSSIBLE_MOVES);

    }
  }
}

// NOTE: long function so it's heavily commented.
void Game::searchAround(int row,
                        int col,
                        char player,
                        vector<Cell> &addTo,
                        char whereFrom) {

  int bSize = this->board.getSize(); // size of board
  int dr = 0, dc = 0; // search around the current cell's neighbors
  int sr = 0, sc = 0; // search coordinates around

  char rival;
  if (player == X) {
    rival = O;
  } else {
    rival = X;
  }

  // search around the current cell
  for (dr = -1; dr <= 1; dr++) {
    for (dc = -1; dc <= 1; dc++) {

      // out of board bounds or on current cell
      if ((dr == 0 && dc == 0) || row + dr < 0 || row + dr >= bSize
          || col + dc < 0 || col + dc >= bSize) {
        continue;
      }

      // got to a rival cell in the perimeter of (row, col)
      if (this->board.getCell(row + dr, col + dc).getSymbol() == rival) {

        // move to rival cell for further search
        sr = row + dr;
        sc = col + dc;

        // UPDATE - add rival
        if(whereFrom == UPDATE) {
          addTo.push_back(this->board.getCell(sr, sc));
        }

        // continue to search as long as you are on rival cell
        for (;;) {

          // search next cell in the rival direction
          sr += dr;
          sc += dc;

          // out of board bounds
          if (sr < 0 || sr >= bSize || sc < 0 || sc >= bSize) {
            break;
          }

          // got to an empty cell
          if (this->board.getCell(sr, sc).getSymbol() == BLANK) {
            break;
          }

          // got to rival cell
          if (this->board.getCell(sr, sc).getSymbol() == rival) {

            // UPDATE - add rival
            if(whereFrom == UPDATE) {
              addTo.push_back(this->board.getCell(sr, sc));
            }

            // POSSIBLE_MOVES - pass

            continue;
          }

          // got to player cell
          if (this->board.getCell(sr, sc).getSymbol() == player) {

            // POSSIBLE_MOVES - add to available moves and break
            if(whereFrom == POSSIBLE_MOVES) {
              Cell possible = this->board.getCell(row, col);
              bool isIn = false;

              // check if cell is already in
              for(int i = 0; i < addTo.size(); i++) {
                if(addTo[i] == possible) { isIn = true; }
              }
              if(!isIn) {
                addTo.push_back(possible);
              }

            } else if(whereFrom == UPDATE) { /* UPDATE - flip all rivals in the
                                                          waY and break */

              for (int i = 0; i < addTo.size(); i++) {
                this->board.setCellSymbol(player, addTo[i].getX(),
                                          addTo[i].getY());

                if(player == X) {
                  this->xCells++;
                  this->oCells--;
                } else {
                  this->oCells++;
                  this->xCells--;
                }
              }
            }

            break;
          }
        }
      }

      // UPDATE - clear -- finished one direction continue to the next
      if(whereFrom == UPDATE) {
        addTo.clear();
      }
    }
  }
}