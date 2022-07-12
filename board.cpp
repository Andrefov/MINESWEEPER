#include "Board.h"


Board::Board(int y, int x, int size, int minesNumber){
	std::random_device rng;																	//
	std::mt19937 minePlanter(rng());														// <- preparing random engine
	std::uniform_int_distribution<std::mt19937::result_type> mineCoordinate(0, (size - 1)); //
	std::vector<Tile> vBuildHelper;  //   <- push helpers for temporary use;
	coordinates pushHelper;			 //
	size_ = size;
	int yPos;
	int xPos;
	for (int i = 0; i < size; i++) {			//	
		for (int j = 0; j < size; j++) {		//  
			vBuildHelper.push_back(Tile());		// <- initializing empty board
		}										//
		board.push_back(vBuildHelper);			//
	}
	for (int i = minesNumber; i > 0; i--) {			// mine planting loop
		yPos = mineCoordinate(minePlanter);
		xPos = mineCoordinate(minePlanter);
		if (board[yPos][xPos].getTileType() == 1 || (yPos == y && xPos == x)) { // checks correct position for int distrubution
			i++;
		}
		else {										// if int distribution is correct
			board[yPos][xPos].setTileType(1);
			pushHelper.y = yPos;
			pushHelper.x = xPos;
			mines.push_back(pushHelper);
		}
	}
}

void Board::setTilesAround() {
	int yPos = 0;
	int xPos = 0;
	int valueSet = 0;
	for (int i = 0; i < mines.size(); i++) {
		yPos = mines[i].y;
		xPos = mines[i].x;
		for (int y_ = std::max(0, yPos - 1); y_ < std::min(size_, yPos + 1); y_++) {
			for (int x_ = std::max(0, xPos - 1); x_ < std::min(size_, xPos + 1); x_++) {
				valueSet = board[y_][x_].getMinesNearby();
				board[y_][x_].setMinesNearby(valueSet++);
			}
		}
	}
}

void Board::fieldReveal(int x, int y)
{
	Tile* t = board.getTile(x, y);
	if (t->getStatus() == 1) {
		return;
	}

	t->setStatus(1);

	if (t->getTileType() == 0 && t->getMinesNearby() == 0) {

		for (int i = x - 1; i <= x + 1; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (   i >= 0 && i < size_ 
					&& j >= 0 && j < size_
					&& !(i == x && j == y)) {
						fieldReveal(i, j);
					}
				}
			}
		}
	}
}


