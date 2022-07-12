#include "gameHandler.h"
#include <iostream>
#include<string>


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
