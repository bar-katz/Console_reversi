
#include "GameFlow.h"

int main() {

  HumanPlayer hp1('X'), hp2('O');
  Player &p1 = hp1;
  Player &p2 = hp2;

  GameFlow g = GameFlow(p1, p2);

  g.run();

  return 0;
}