#include "menu.h"

void menu::welcomeSign() {

	std::cout << std::endl;
	std::cout << "   (                                                                           \n";
	std::cout << "   )\\))(    (              (         (  (       (      (              (    (    \n";
	std::cout << "  ((_)()\\   )\\    (       ))\\   (    )\\))(     ))\\    ))\\   `  )     ))\\   )(   \n";
	std::cout << "  (_()((_) ((_)   )\\ )   /((_)  )\\  ((_)()\\   /((_)  /((_)  /(/(    /((_) (()\\  \n";
	std::cout << "  |  \\/  |  (_)  _(_/(  (_))   ((_) _(()((_) (_))   (_))   ((_)_\\  (_))    ((_) \n";
	std::cout << "  | |\\/| |  | | | ' \\)) / -_)  (_-< \\ V  V / / -_)  / -_)  | '_ \\) / -_)  | '_| \n";
	std::cout << "  |_|  |_|  |_| |_||_|  \\___|  /__/  \\_/\\_/  \\___|  \\___|  | .__/  \\___|  |_|   \n";
	std::cout << "                                                           |_|                  \n";
}

void menu::mainMenu() {
	
	welcomeSign();
	std::cout << "*********************** MENU ****************************\n";
	std::cout << "                    1 - PLAY                             \n";
	std::cout << "                    2 - ABOUT THE GAME                   \n";
	std::cout << "                    3 - EXIT                             \n";
	std::cout << "*********************************************************\n";
}

void menu::menuChoice(int choice) {

	switch (choice) {
	case 1:
		levelChoosing(getChoice(1));
	case 2:
		aboutTheGame();
		break; 
	case 3:
		system("cls");
		std::cout << " (                     (         )                \n";
		std::cout << " )\\ )                  )\\ )   ( /(   (        (   \n";
		std::cout << "(()/(      (     (    (()/(   )\\())  )\\ )    ))\\  \n";
		std::cout << " /(_))_    )\\    )\\    ((_)) ((_)\\  (()/(   /((_) \n";
		std::cout << "(_)) __|  ((_)  ((_)   _| |  | |(_)  )(_)) (_))   \n";
		std::cout << "  | (_ | / _ \\ / _ \\ / _` |  | '_ \\ | || | / -_)  \n";
		std::cout << "   \\___| \\___/ \\___/ \\__,_|  |_.__/  \\_, | \\___|  \n";
		std::cout << "                                     |__/         \n";
		break;
	}
}

void menu::levels() {
	system("cls");
	std::cout << "****************** DIFFICULTY LEVEL *********************\n";
	std::cout << "          1 - BEGGINER (9x9 board, 10 mines)              \n";
	std::cout << "          2 - INTERMEDIATE (16x16 board, 40 mines)        \n";
	std::cout << "          3 - ADVANCED (24x24 board, 99 mines)           \n";
	std::cout << "*********************************************************\n";
}

int menu::getChoice(int displaySelector) {
	while (true) {
		if (displaySelector == 0) {
			mainMenu();
		}
		else if (displaySelector == 1) {
			levels();
		}
		std::cin >> choice;
		if ((choice == 1 || choice == 2 || choice == 3))
			return choice;
		else {
			std::cout << "Wrong input, try again\n";
			system("pause");
			system("cls");
		}
	}
}

void menu::levelChoosing(int levelchoice) {
	switch (levelchoice) {
	case 1: 
		//begginer mode
		minesQuant = 10;
		boardSize = 9;
		break;
	case 2:
		//intermediate mode
		minesQuant = 40;
		boardSize = 16;
		break;
	case 3:
		//advanced mode
		minesQuant = 99;
		boardSize = 24;
		break;
	}
}

void menu::aboutTheGame()
{
	std::cout << "\n******************************* ABOUT THE GAME  ***********************************\n\n";
	std::cout << "You will have to clear a rectangular board containing hidden mines\nwithout detonating any of them. If you choose the cell with the bomb- you die!\n\n";
	std::cout << "You will be provided with the clues about the number of neighboring mines in each field.\nThis way, you can deduce which cell is empty.";
	std::cout << " Your first move is guaranteed to be safe.\n\n";
	std::cout << "                                  Good luck!\n";
	std::cout << "*************************************************************************************\n\n";
	system("pause");
	system("cls");
}


void menu::displayMenu()
{
	mainMenu();
	menuChoice(getChoice(0));
}