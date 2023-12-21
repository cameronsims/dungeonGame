#include "Keyboard.hpp"

#include <windows.h>

dungeon::Movement dungeon::Keyboard::getMovementInput() {
	// If W is pressed
	if (this->isDown('W')) {
		return dungeon::Movement::MOVE_UP;
	}
	// If S is pressed
	if (this->isDown('S')) {
		return dungeon::Movement::MOVE_DOWN;
	}
	// If A is pressed
	if (this->isDown('A')) {
		return dungeon::Movement::MOVE_LEFT;
	}
	// If D is pressed
	if (this->isDown('D')) {
		return dungeon::Movement::MOVE_RIGHT;
	}
	return dungeon::Movement::MOVE_STILL;
}

bool dungeon::Keyboard::getPauseInput() {
	return this->isDown('Q');
}

bool dungeon::Keyboard::isDown(char pKey) {
	// Pressed constant
	constexpr short pressed = 0x8000;
	return (GetKeyState(pKey) & pressed);
}