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
	void getCoordinates();
	bool checkNumbers(char c);
	bool chceckLetters(char c);
	void markMine(int y, int x, Board* myBoard, int status); // decrementuje int mines
	void action(Board* myBoard, int switch_);
	bool winCondition(Board* myBoard); // je¿eli mines = 0
	bool loseCondition(Board* myBoard);
	void winningSign();
	void losingSign();
	int round();
	
};

