#include <array>
#include <random>
#include <iostream>
#include <algorithm>
#include "tile.h"

class Board {
private:
	struct coordinates
	{
		int y;
		int x;
	};
	int size_;
	int minesNumber;
	std::vector<std::vector <Tile>> board;
	std::vector<coordinates> mines;
	
public:
	void displayBoard();
	//konstruktor kopiujacy
	Board(int y, int x, int size, int minesNumber);
	Tile* getTile(int y, int x);
	void setTilesAround();
	void fieldReveal(int x,int y);
	vector<> getNeighbors();
};
