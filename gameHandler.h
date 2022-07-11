#pragma once
class gameHandler
{
	int x;
	int y;
	int mines;

public:
	void getCoordinates(int *y, int *x);
	int coordinatesVerificator(int y, int x);
	void markMine(int y, int x); // decrementuje int mines 
	int WinCondition(); // je¿eli mines = 0
	void winningSign();
	void losingSign();
};

