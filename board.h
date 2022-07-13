#pragma once
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
	void firstLine(int y, int x);
	void middleLine(int y, int x);
	void printTile(int y, int x);
	void separatorLine(int y, int x);
	void lastLine(int y, int x);
	Board(int y, int x, int size, int minesNumber);
	Tile* getTile(int y, int x);
	void setTilesAround();
	void fieldReveal(int x,int y, Board *board_);
	//vector<> getNeighbors();
};



