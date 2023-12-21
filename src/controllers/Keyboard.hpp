#pragma once

#include "Controller.hpp"

namespace dungeon {
	class Keyboard : public Controller {
	public:
		Movement getMovementInput();
		bool getPauseInput();
		bool isDown(char pKey);
	};
}