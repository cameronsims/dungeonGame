#pragma once

#include "Room.hpp"
#include "Entity.hpp"

#include <vector>

namespace dungeon {
	enum consoleColours { COLOUR_BLACK = 0, COLOUR_BLUE, COLOUR_GREEN, COLOUR_CYAN, COLOUR_RED, COLOUR_MAGENTA, COLOUR_BROWN, COLOUR_LIGHTGRAY,
		COLOUR_DARKGRAY, COLOUR_LIGHTBLUE, COLOUR_LIGHTGREEN, COLOUR_LIGHTCYAN, COLOUR_LIGHTRED, COLOUR_LIGHTMEGENTA, COLOUR_YELLOW, COLOUR_WHITE};

	void printRoom(dungeon::Room* rooms, size_t roomSize, dungeon::Entity& player, std::vector<dungeon::Entity>& entities);
	void printMap(unsigned int currentRoom, size_t roomSize);
	void clearConsole();
}