#pragma once

#include "Dungeon.hpp"
#include "Room.hpp"

#include <vector>

namespace dungeon {
	void generateRooms(dungeon::Room* rooms, dungeon::Dungeon& d, std::vector<size_t> path);

	bool isInPath(std::vector<size_t> path, size_t location);

	void createRoom(dungeon::Room& pRoom, unsigned int pLength, unsigned int pHeight, size_t currentRoom, dungeon::Dungeon& d, dungeonType* pTypes, dungeonColour pMode);

	void createWalls(Room& pRoom, unsigned int pLength, unsigned int pHeight, dungeon::dungeonType* pTypes, size_t currentRoom, dungeon::Dungeon& d);
	void createDoors(Room& pRoom, unsigned int pLength, unsigned int pHeight, dungeon::dungeonType* pTypes, size_t currentRoom, dungeon::Dungeon& d);
	void fillHorizontalWall(Room& pRoom, unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize);
	void fillVerticalWall(Room& pRoom, unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize);
}