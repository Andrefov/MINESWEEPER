#include <iostream>
#include<string>
#include"board.h"
#include "gameHandler.h"
#include "tile.h"


void gameHandler::markMine(int y, int x, Board* myBoard, int status)
{
    Tile* t = myBoard->getTile(y, x);
    t->setStatus(status);
}

void gameHandler::action(Board* myBoard)
{
    std::string action;
    std::cout << "What do you want to do? Type \"discover\" to discover the field, \"mark\" to marka a filed as flag or \"unmark\" to unmark the field" << std::endl;
    while (true) {
        std::cout << ">>";
        std::cin >> action;

        if ((action == "discover") || (action == "d")) {
            getCoordinates(&y, &x);
            //metoda odkrywajaca pola
        }
        else if ((action == "mark") || (action == "m")) {
            getCoordinates(&y, &x);
            markMine(x, y,myBoard, 9);
        }
        else if ((action == "unmark") || (action == "u")) {
            getCoordinates(&y, &x);
            markMine(x, y, myBoard, 0);
        }
        else if (action == "Exit" || action == "exit")
            exit(0);

        else {
            std::cout << "Invalid input. Try again!" << std::endl;
            continue;
        }
    }
    
}


bool gameHandler::checkNumbers(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

bool gameHandler::chceckLetters(char c) {
    if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
        return true;
    return false;
}


void gameHandler::getCoordinates(int* y, int* x) {
    std::string coordinates;
    while (true) {
        std::cout << "Input coordinates: " << std::endl;

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
