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
	//int coordinatesVerificator(int y, int x);
	void markMine(int y, int x); // decrementuje int mines 
	int WinCondition(); // je¿eli mines = 0
};

