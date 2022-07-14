#pragma once
#include <iostream>
#include<string>
#include"board.h"
#include<algorithm>

class GameHandler
{
	int x;
	int y;
	int mines;
	int moveType;

public:
	void getCoordinates(int size);
	bool checkNumbers(char c);
	bool chceckLetters(char c, int size);
	void markMine(int y, int x, Board* myBoard, int status); // decrementuje int mines
	void action(Board* myBoard, int switch_);
	bool winCondition(Board* myBoard); // je¿eli mines = 0
	bool loseCondition(Board* myBoard, int moveType);
	void winningSign();
	void losingSign();
	void goodbye();
	int round();
	
};

