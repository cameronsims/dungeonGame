#pragma once

#include "../rooms/DungeonMeta.hpp"

namespace dungeon {

	class Controller {
	private:
		static const char* name;
	public: 
		Movement getMovementInput();
		bool     getPauseInput();

		bool isDown(char pKey);
	};
}