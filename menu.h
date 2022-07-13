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
	void menuChoice();
	void levels();
	void levelChoosing();
	void aboutTheGame();
	void displayMenu();
	int getMinesQuant();
	int getBoardSize();

private:
	int minesQuant, boardSize; //=mines quantity, size of a board's side
};
