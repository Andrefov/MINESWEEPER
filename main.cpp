#pragma once
#include <iostream>
#include "board.h"
#include "menu.h"
#include "gameHandler.h"


int main() {
	Menu menu;
	menu.displayMenu();
	GameHandler  gh;
	Board board_(5, 5, menu.getBoardSize(), menu.getMinesQuant());
	board_.setTilesAround();
	board_.displayBoard();

	return 0;
}