#pragma once
class gameHandler
{
	int x;
	int y;
	int mines;

public:
	void getCoordinates(int *y, int *x);
	bool checkNumbers(char c);
	bool chceckLetters(char c);
	void markMine(int y, int x, Board myBoard); // decrementuje int mines
	void action(Board myBoard);
	int WinCondition(); // je¿eli mines = 0
};

