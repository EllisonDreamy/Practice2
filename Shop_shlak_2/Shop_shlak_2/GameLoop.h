#pragma once
#include "Listik.h"

void initTerminal();
Listik gamePrep(int leng);
int gameLoop(Listik gameData, int optionsAmount, int scoreAddition = 10,
             int scoreSubtraction = 5);
