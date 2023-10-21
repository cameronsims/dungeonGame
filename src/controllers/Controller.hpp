#pragma once

namespace dungeon {
	enum class Movement {
		MOVE_STILL = 0,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT
	};

	class Controller {
	private:
		static const char* name;
	public: 
		Movement getMovementInput();
	};
}