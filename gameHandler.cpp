#include <iostream>
#include<string>
#include"board.h"
#include "gameHandler.h"
#include "tile.h"
#include "menu.h"

void GameHandler::markMine(int y, int x, Board* myBoard, int status)
{
    Tile* t = myBoard->getTile(y, x);
    t->setStatus(status);
}

void GameHandler::action(Board* myBoard)
{
    std::string action;
    std::cout << "What do you want to do? Type \"discover\" to discover the field, \"mark\" to marka a filed as flag or \"unmark\" to unmark the field" << std::endl;
    while (true) {
        std::cout << ">>";
        std::cin >> action;

        if ((action == "discover") || (action == "d")) {
            getCoordinates(&y, &x);
            myBoard->fieldReveal(y, x);
        }
        else if ((action == "mark") || (action == "m")) {
            getCoordinates(&y, &x);
            markMine(x, y,myBoard, 9);
        }
        else if ((action == "unmark") || (action == "u")) {
            getCoordinates(&y, &x);
            markMine(x, y, myBoard, 0);
        }
        else {
            std::cout << "Invalid input. Try again!" << std::endl;
            continue;
        }
    }  
}

bool GameHandler::checkNumbers(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool GameHandler::chceckLetters(char c) {
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
        return true;
    return false;
}


void GameHandler::getCoordinates(int* y, int* x) {
    std::string coordinates;
    while (true) {
        std::cout << "Input coordinates: " << std::endl;

        if (!(std::cin >> coordinates))
        {
            std::cout << "Insert a letter than a number" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        //sprawdzam czy jest litera i conajwyzej 2cyfry
        if (coordinates.size() >3) {
            std::cout << "Enter one letter and number" << std::endl;
            continue;
        }
        //sprawdzam czy litera jest pierwsza
        else if (chceckLetters(coordinates[0]) == 0) {
            std::cout << "Input a letter (the size of the letter is irrelevant)!" << std::endl;
            continue;
        }
        //sprawdzam czy na drugim miejscu jest cyfra
        else if (checkNumbers(coordinates[1]) == 0) {
            std::cout << "Input a proper number!" << std::endl;
            continue;
        }
        //jak wyzej
        else if (checkNumbers(coordinates[2]) == 0)
            continue;

        break;
    }

    std::string number;
    int num;
    number += coordinates[1];
    number += coordinates[2];
    num = stoi(number) - 1;//zmiana typu zmiennej (string do int)
    *y = toupper(coordinates[0]) - 65;//zmiana litery na odpowiednia cyfre
    *x = num;
    
}

void GameHandler::winningSign() {

	std::cout << std::endl;
	std::cout << "__   __                                     \n";
	std::cout << "\\ \\ / /	     Congratulations!               \n";
	std::cout << " \\ V / ___   _   _   __      __ ___   _ __  \n";
	std::cout << "  \\ / / _ \\ | | | |  \\ \\ /\\ / // _ \\ | '_ \\ \n";
	std::cout << "  | || (_) || |_| |   \\ V  V /| (_) || | | |\n";
	std::cout << "  \\_/ \\___/  \\__,_|    \\_/\\_/  \\___/ |_| |_|\n";
	std::cout << "\n";
}
void GameHandler::losingSign() {

	std::cout << std::endl;
	std::cout << "__   __                                 \n";
	std::cout << "\\ \\ / /               _              _       \n";
	std::cout << " \\ V / ___   _   _   | |  ___   ___ | |_ \n";
	std::cout << "  \\ / / _ \\ | | | |  | | / _ \\ / __|| __|\n";
	std::cout << "  | || (_) || |_| |  | || (_) |\\__ \\| |_ \n";
	std::cout << "  \\_/ \\___/  \\__,_|  |_| \\___/ |___/ \\__|\n\n";
	std::cout << "  Try again!\n";

};

int GameHandler::round() {
    Menu menu;
    if (menu.displayMenu() == 0) {
        menu.goodbye();
        return 0;
   }
    Board board_ (menu.getBoardSize());
    board_.displayBoard();
    getCoordinates(&y, &x);
    board_.plantMines(y, x, menu.getBoardSize(), menu.getMinesQuant());
    board_.setTilesAround();
    while (winCondition() == false || loseCondition() == false) {
        action(&board_);
    }
   
    board_.displayBoard();
}
