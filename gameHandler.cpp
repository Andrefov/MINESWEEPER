#include "gameHandler.h"

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
