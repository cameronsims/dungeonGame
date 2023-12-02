#pragma once

#include "Room.hpp"

#include <vector>

namespace dungeon {
	void generateRooms(dungeon::Room* rooms, size_t roomSize, std::vector<size_t> path);
	void generateRooms(dungeon::Room* rooms, size_t roomSize, unsigned int pWidth, unsigned int pHeight, dungeonColour clr);

	bool isInPath(std::vector<size_t> path, size_t location);
}