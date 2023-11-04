#pragma once

#include <windows.h>

#include "Controller.hpp"

namespace dungeon {
	class Keyboard : public Controller {
	public:
		Movement getMovementInput();
		bool getPauseInput();
		bool isDown(char pKey);
	};
}