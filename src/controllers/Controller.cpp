#include <stdio.h>

#include "Controller.hpp"

dungeon::Movement dungeon::Controller::getMovementInput() {
	printf("Unknown Input!");
	return dungeon::Movement::MOVE_STILL;
}

const char* dungeon::Controller::name = "Unknown Input";