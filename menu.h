#pragma once
#include <iostream>
#include <string>
#include <windows.h>

class Menu
{
public:
	int choice, levelchoice;
	void welcomeSign();
	void mainMenu();
	int getChoice(int displaySelector);
	int menuChoice();
	void levels();
	void levelChoosing();
	void aboutTheGame();
	int displayMenu();
	int getMinesQuant();
	int getBoardSize();
	void goodbye();

private:
	int minesQuant, boardSize; //=mines quantity, size of a board's side
};
