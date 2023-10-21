#include "Keyboard.hpp"

dungeon::Movement dungeon::Keyboard::getMovementInput() {
	// Pressed constant
	constexpr short pressed = 0x8000;
	// If W is pressed
	if (GetKeyState('W') & pressed) {
		return dungeon::Movement::MOVE_UP;
	}
	// If S is pressed
	if (GetKeyState('S') & pressed) {
		return dungeon::Movement::MOVE_DOWN;
	}
	// If A is pressed
	if (GetKeyState('A') & pressed) {
		return dungeon::Movement::MOVE_LEFT;
	}
	// If D is pressed
	if (GetKeyState('D') & pressed) {
		return dungeon::Movement::MOVE_RIGHT;
	}
	return dungeon::Movement::MOVE_STILL;
}