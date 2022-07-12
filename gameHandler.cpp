#include "gameHandler.h"
#include <iostream>


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

//int gameHandler::coordinatesVerificator(int y, int x)
//{
//    
//}

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

        if (coordinates.size() != 2) {
            std::cout << "Enter one letter and one digit each" << std::endl;
            continue;
        }

        else if (chceckLetters(coordinates[0]) == 0) {
            std::cout << "Input a letter (the size of the letter is irrelevant)!" << std::endl;
            continue;
        }

        else if (checkNumbers(coordinates[1]) == 0) {
            std::cout << "Input a proper number beetwen 1 and 9!" << std::endl;
            continue;
        }
        break;
    }
    //
    *y = toupper(coordinates[0]) - 65;
    *x = coordinates[1] - 48;
    
}
void gameHandler::winningSign() {

    std::cout << std::endl;
    std::cout << "__   __                                     \n";
    std::cout << "\\ \\ / /	     Congratulations!               \n";
    std::cout << " \\ V / ___   _   _   __      __ ___   _ __  \n";
    std::cout << "  \\ / / _ \\ | | | |  \\ \\ /\\ / // _ \\ | '_ \\ \n";
    std::cout << "  | || (_) || |_| |   \\ V  V /| (_) || | | |\n";
    std::cout << "  \\_/ \\___/  \\__,_|    \\_/\\_/  \\___/ |_| |_|\n";
    std::cout << "\n";
}
void gameHandler::losingSign() {

    std::cout << std::endl;
    std::cout << "__   __                                 \n";
    std::cout << "\\ \\ / /               _              _       \n";
    std::cout << " \\ V / ___   _   _   | |  ___   ___ | |_ \n";
    std::cout << "  \\ / / _ \\ | | | |  | | / _ \\ / __|| __|\n";
    std::cout << "  | || (_) || |_| |  | || (_) |\\__ \\| |_ \n";
    std::cout << "  \\_/ \\___/  \\__,_|  |_| \\___/ |___/ \\__|\n\n";
    std::cout << "  Try again!\n";

};

