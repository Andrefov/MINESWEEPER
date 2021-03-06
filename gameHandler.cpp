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
    std::cout << "What do you want to do? Type \"discover\" to discover the field, \"mark\" to mark a field as flag or \"unmark\" to unmark the field" << std::endl;
    while (true) {
        std::cout << ">>";
        std::cin >> action;

        if ((action == "discover") || (action == "d")) {
            getCoordinates(myBoard->getBoardSize());
            if (switch_ == 0) {
                myBoard->fieldReveal(y, x);
                moveType = 0;
                break;
            }
            break;
        }
        else if ((action == "mark") || (action == "m")) {
            getCoordinates(myBoard->getBoardSize());
            Tile* t = myBoard->getTile(y, x);
            if (t->getStatus() == 0) {
                markMine(y, x, myBoard, 9);
                mines++;
                moveType = 1;
                break;
            }
            else {
                std::cout << "You can't mark the discoverd field!" << std::endl;
                continue;
            }
        }
        else if ((action == "unmark") || (action == "u")) {
            getCoordinates(myBoard->getBoardSize());
            Tile* t = myBoard->getTile(y, x);
            if (t->getStatus() == 9) {
                markMine(y, x, myBoard, 0);
                mines--;
                moveType = 2;
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

bool GameHandler::loseCondition(Board* myBoard, int moveType){
    if (myBoard->getTile(y, x)->getTileType() == 1 && moveType == 0) {
        myBoard->getTile(x, y)->setStatus(1);
        myBoard->displayBoard();
        losingSign();
        return true;
    }
    else {
        return false;
    }
}

bool GameHandler::winCondition(Board* myBoard) {
    int temp = pow(myBoard->getBoardSize(), 2);
    if ((pow(myBoard->getBoardSize(), 2) - myBoard->getMinesNumber()) == myBoard->getRevealedFields()) {
        myBoard->displayBoard();
        winningSign();
        return true;
    }
    else {
        return false;
    }
}

bool GameHandler::checkNumbers(char c){
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool GameHandler::chceckLetters(char c, int boardSize) {
    if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && ((c <= 'a' + boardSize) || (c <= 'A' + boardSize)))
        return true;
    return false;
}

void GameHandler::getCoordinates(int boardSize) {
    std::string coordinates;
    int letter;
    int number;

    while (true) {
        std::cout << "Input coordinates (e.x A1): " << std::endl;

        std::cin >> coordinates;
        if (coordinates == "Exit" || coordinates == "exit") {
            goodbye();
            exit(0);
        }
        //sprawdzam czy jest litera i conajwyzej 2cyfry
        if (coordinates.size() > 3) {
            std::cout << "Enter one letter and number" << std::endl;
            continue;
        }
        //sprawdzam czy litera jest pierwsza
        else if (chceckLetters(coordinates[0], boardSize) == 0) {
            std::cout << "enter the letter contained in the board (the size of the letter is irrelevant)!" << std::endl;
            continue;
        }
        letter = toupper(coordinates[0]) - 65;
        coordinates.erase(0, 1);

        if (coordinates.size() < 2) {
            if (checkNumbers(coordinates[0]) == 0) {
                std::cout << "Enter a number"<<std::endl;
                continue;
            }
        }
        else {
            if ((checkNumbers(coordinates[0]) && checkNumbers(coordinates[1])) == 0) {
                std::cout << "Enter a number"<<std::endl;
                continue;
            }
        }
        number = stoi(coordinates) - 1;

        if (number >= boardSize) {
            std::cout << "Enter a number that is less than the size of the array";
            continue;
        }
        break;
    }
    x = letter;
    y = number;
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

void GameHandler::goodbye() {
    system("cls");
    std::cout << " (                     (         )                \n";
    std::cout << " )\\ )                  )\\ )   ( /(   (        (   \n";
    std::cout << "(()/(      (     (    (()/(   )\\())  )\\ )    ))\\  \n";
    std::cout << " /(_))_    )\\    )\\    ((_)) ((_)\\  (()/(   /((_) \n";
    std::cout << "(_)) __|  ((_)  ((_)   _| |  | |(_)  )(_)) (_))   \n";
    std::cout << "  | (_ | / _ \\ / _ \\ / _` |  | '_ \\ | || | / -_)  \n";
    std::cout << "   \\___| \\___/ \\___/ \\__,_|  |_.__/  \\_, | \\___|  \n";
    std::cout << "                                     |__/         \n";
}

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
    while (loseCondition(&board_, moveType) == false && winCondition(&board_) == false) {
        board_.displayBoard();
        action(&board_, 0);

    } 
}
