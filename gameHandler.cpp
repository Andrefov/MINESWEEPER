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

void GameHandler::action(Board* myBoard, int switch_)
    {
    std::string action;
    std::cout << "What do you want to do? Type \"discover\" to discover the field, \"mark\" to marka a filed as flag or \"unmark\" to unmark the field" << std::endl;
    while (true) {
        std::cout << ">>";
        std::cin >> action;

        if ((action == "discover") || (action == "d")) {
            getCoordinates();
            if (switch_ == 0) {
                myBoard->fieldReveal(y, x);
                break;
            }
            break;
        }
        else if ((action == "mark") || (action == "m")) {
            getCoordinates();
            Tile* t = myBoard->getTile(y, x);
            if (t->getStatus() == 0) {
                markMine(x, y, myBoard, 9);
                mines++;
                break;
            }
            else {
                std::cout << "You can't mark the discoverd field!" << std::endl;
                continue;
            }
        }
        else if ((action == "unmark") || (action == "u")) {
            getCoordinates();
            Tile* t = myBoard->getTile(y, x);
            if (t->getStatus() == 9) {
                markMine(x, y, myBoard, 0);
                mines--;
                break;
            }
            else {
                std::cout << "You can't unmark the field you didn't mark earlier!" << std::endl;
                continue;
            }
        }
        else {
            std::cout << "Invalid input. Try again!" << std::endl;
            continue;
        }
    }
}

bool GameHandler::loseCondition(Board* myBoard){
    Tile* t = myBoard->getTile(y, x);
    if (t->getTileType() == 1)
        return true;
    return false;
}

bool GameHandler::winCondition(Board* myBoard) {
    return false;
}

bool GameHandler::checkNumbers(char c){
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool GameHandler::chceckLetters(char c) {
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
        return true;
    return false;
}

void GameHandler::getCoordinates() {
    std::string coordinates;
    while (true) {
        std::cout << "Input coordinates (e.x A1): " << std::endl;

        std::cin >> coordinates;
        if (coordinates == "Exit" || coordinates == "exit")
            exit(0);

        //sprawdzam czy jest litera i conajwyzej 2cyfry
        if (coordinates.size() > 3) {
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
       // else if (checkNumbers(coordinates[2]) == 0)
           // continue;

        break;
    }
    std::string number;
    int num;
    number += coordinates[1];
    number += coordinates[2];
    num = stoi(number) - 1;//zmiana typu zmiennej (string do int)
    y = toupper(coordinates[0]) - 65;//zmiana litery na odpowiednia cyfre
    x = num;
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
    if (menu.menuChoice() == 0) {
        menu.goodbye();
        return 0;
   }
    Board board_ (menu.getBoardSize());
    board_.displayBoard();
    action(&board_, 1);
    board_.plantMines(y, x, menu.getBoardSize(), menu.getMinesQuant());
    board_.setTilesAround();
    board_.fieldReveal(y, x);
    while (winCondition(&board_) == false || loseCondition(&board_) == false) {
        board_.displayBoard();
        action(&board_, 0);
    } 
    board_.displayBoard();
}
