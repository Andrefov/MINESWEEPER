#include <array>
#include <random>
#include <iostream>
#include "tile.h"

class Board {
private:
	int size_;
	std::array<std::array <tile, const size_>,const size_> board;
	//vector typu struct (int y, int x)

public:
	Board(int y, int x);
	void displayBoard();
	//konstruktor kopiuj¹cy
	// konstruktor parametryczny (wylosuje miny)
	tile* getTile(int y, int x);
	void setTilesAround(int y, int x);
	
	void fieldReveal();

};

Board::Board(int y, int x) {
	std::cout << "tworzenie tablicy..."
		// pêtla dla iloœci min
		// 
		//random generator
		// jezeli koordynaty == gracz losuj dalej 

		board[][]





}
