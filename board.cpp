#include "Board.h"

void Board::displayBoard() {
	int firstline = 0;
	int lastline = 0;
	int hseparator = 1;

	std::cout << "     ";

	for (int x = 0; x < board.size(); x++) {
		std::cout << (char)('A' + x) << "   ";
	}
	std::cout << std::endl;
	for (int y = 0; y < board.size(); y++) {



		for (int x = 0; x < board.size(); x++) { //185 186 187 188 201 202 204
			if (y == 0 && firstline == 0) {
				firstLine(y, x);	
			}
			else if (firstline == 1 && hseparator == 1 && lastline == 0) {
				middleLine(y, x);
			}
			else if (y < board.size()-1 && hseparator == 0) {
				separatorLine(y, x);
			}
			else if (y == board.size() - 1 && hseparator == 1 && lastline == 1) {
				lastLine(y, x);
			}
			
		}
		if (firstline == 0) {
			firstline = 1;
			y--;
		}
		else if (y == board.size() - 1 && lastline == 0) {
			lastline = 1;
			y--;
		}
		else if (hseparator == 1) {
			hseparator = 0;
			y--;
		}
		
		else if (hseparator == 0) {
			hseparator = 1;
		}
		
		std::cout << std::endl;
	}

}

void Board::firstLine(int y, int x) {
	if (x == 0) {

		std::cout <<"   " << char(201) << char(205) << char(205) << char(205);
	}
	else if (x > 0 && x < board.size() - 1) {
		std::cout << char(203) << char(205) << char(205) << char(205);
	}
	else if (x == board.size() - 1) {
		std::cout << char(203) << char(205) << char(205) << char(205) << char(187);
	}
}

void Board::middleLine(int y, int x) {
	if (x == 0) {
		if (y+1 < 10)
			std::cout << y+1 << "  ";
		else
			std::cout << y+1 << " ";
	}
	std::cout << char(186) << ' ';
	printTile(y, x);
	std::cout << ' ';
	if (x == board.size() - 1) {
		std::cout << char(186);
	}
}

void Board::separatorLine(int y, int x) {

	if (x == 0) {
		std::cout <<"   "<< char(204) << char(205) << char(205) << char(205);
	}
	else if (x > 0 && x < board.size() - 1) {
		std::cout << char(206) << char(205) << char(205) << char(205);
	}
	else if (x == board.size() - 1) {
		std::cout << char(206) << char(205) << char(205) << char(205) << char(185);
	}
}

void Board::lastLine(int y, int x) {
	if (x == 0) {
		std::cout <<"   "<< char(200) << char(205) << char(205) << char(205);
	}
	else if (x > 0 && x < board.size() - 1) {
		std::cout << char(202) << char(205) << char(205) << char(205);
	}
	else if (x == board.size() - 1) {
		std::cout << char(202) << char(205) << char(205) << char(205) << char(188);
	}
}

void Board::printTile(int y, int x) {
	if (board[y][x].getMinesNearby() > 0 && board[y][x].getStatus() == 1 && board[y][x].getTileType() == 0) {
		std::cout << board[y][x].getMinesNearby();
	}
	else if (board[y][x].getMinesNearby() == 0 && board[y][x].getStatus() == 1 && board[y][x].getTileType() == 0) {
		std::cout << ' ';
	}
	else if (board[y][x].getStatus() == 0 && board[y][x].getStatus() != 9) {
		std::cout << char(178);
	}
	else if (board[y][x].getStatus() == 0 && board[y][x].getStatus() == 9) {
		std::cout << 'F';
	}
	else if (board[y][x].getTileType() == 1 && board[y][x].getStatus() == 1) {
		std::cout << char(233);
	}
}

Board::Board(int size) {
	std::vector<Tile> vBuildHelper;  //   <- push helpers for temporary use;
	size_ = size;
	for (int i = 0; i < size; i++) {			//	
		for (int j = 0; j < size; j++) {		//  
			vBuildHelper.push_back(Tile());		// <- initializing empty board
		}										//
		board.push_back(vBuildHelper);			//
	}
}
	


Tile* Board::getTile(int y, int x)
{
	Tile* ptr = &board[y][x];
	return ptr;
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

void Board::fieldReveal(int x, int y )
{
	Tile *t = &board[x][y];
	if (t->getStatus() != 1) {

		t->setStatus(1);

		if (t->getTileType() == 0 && t->getMinesNearby() == 0) {

			for (int i = x - 1; i <= x + 1; i++) {
				for (int j = y - 1; j <= y + 1; j++) {
					if (i >= 0 && i < size_
						&& j >= 0 && j < size_
						&& !(i == x && j == y)) {
						fieldReveal(i, j);
					}
				}
			}
		}
	}
}

void Board::plantMines(int y, int x, int size, int mines_) {
	std::random_device rng;																	//
	std::mt19937 minePlanter(rng());														// <- preparing random engine
	std::uniform_int_distribution<std::mt19937::result_type> mineCoordinate(0, (size - 1)); //
	coordinates pushHelper;	
	int yPos;
	int xPos;
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
