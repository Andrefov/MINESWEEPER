#pragma once
#include <iostream>
#include <windows.h>

class menu
{
public:
	int choice, levelchoice;
	void welcomeSign();
	void mainMenu();
	int getChoice(int displaySelector);
	void menuChoice(int choice);
	void levels();
	void levelChoosing(int levelchoice);
	void aboutTheGame();
	void displayMenu();

private:
	int minesQuant, boardSize; //=mines quantity, size of a board's side
};
