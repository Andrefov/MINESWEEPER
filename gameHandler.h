#pragma once
#include <iostream>
#include<string>
#include"board.h"

class GameHandler
{
	int x;
	int y;
	int mines;

public:
	void getCoordinates(int *y, int *x);
	bool checkNumbers(char c);
	bool chceckLetters(char c);
	void markMine(int y, int x, Board* myBoard, int status); // decrementuje int mines
	void action(Board* myBoard);
	bool winCondition() { return false; } // je¿eli mines = 0
	bool loseCondition(){ return false; }
	void winningSign();
	void losingSign();
	int round();
};

