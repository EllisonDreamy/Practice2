#include "GameLoop.h"
#include <iostream>
#include "Listik.h"
int main()
{
	Listik gameData = gamePrep();
	return gameLoop(gameData);
}
