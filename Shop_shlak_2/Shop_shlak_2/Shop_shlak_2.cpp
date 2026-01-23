#include <iostream>

#include "GameLoop.h"
#include "Listik.h"
int main() {
  srand(time(NULL));
  initTerminal();
  Listik gameData = gamePrep(10);
  return gameLoop(gameData, 4);
}