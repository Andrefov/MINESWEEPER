#pragma once
#include <iostream>
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
};

