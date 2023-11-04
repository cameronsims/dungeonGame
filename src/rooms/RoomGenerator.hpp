#pragma once

#include "Room.hpp"

namespace dungeon {
	void generateRooms(dungeon::Room* rooms, unsigned int width, unsigned int height, size_t roomSize, dungeonColour clr);
}