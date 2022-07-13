#pragma once
#include <iostream>
#include "board.h"
#include "menu.h"
#include "gameHandler.h"


int main() {
	GameHandler  gh;
	if (gh.round() == 0) {
		return 0;
	}
}