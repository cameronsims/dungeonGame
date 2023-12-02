#pragma once

#include "../rooms/Room.hpp"
#include "../entities/Entity.hpp"

#include <vector>

namespace dungeon {
	void printRoom(dungeon::Room* rooms, size_t roomSize, dungeon::Entity& player, ENTITIES& entities);
	void printMap(Room* rooms, unsigned int currentRoom, size_t roomSize);
	void clearConsole();
}