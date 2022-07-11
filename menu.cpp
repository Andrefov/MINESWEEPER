#include "menu.h"
#include <iostream>
#include <windows.h>


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

void menu::getChoice() {
	std::cin >> choice;
	while (true) {
		welcomeSign();
		if ((choice == 1 || choice == 2 || choice == 3))
			break;
		else {
			std::cout << "Wrong input, try again\n";
			system("pause");
			system("cls");
		}
	}
}

void menu::menuChoice(int choice) {

	switch (choice) {
	case 1:
		levels();
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


void menu::levelChoosing(int levelchoice) {
	//czy to już ma być w gamehandlerze?
	switch (levelchoice) {
	case 1:
		//begginer mode
		break;
	case 2:
		//intermediate mode
		break;
	case 3:
		//advanced mode
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


