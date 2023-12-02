#include "RoomGenerator.hpp"

#include "DungeonMeta.hpp"
#include "Room.hpp"
#include "../random/Random.hpp"

#include <vector>

void dungeon::generateRooms(dungeon::Room* rooms, size_t roomSize, std::vector<size_t> path) {
	dungeon::dungeonColour clr;
	dungeon::dungeonType type;
	unsigned int height, length, seed;

	// If it's in the path, then define it as normal (besides start and end
	for (std::vector<size_t>::iterator s = path.begin(); s != path.end(); s++) {
		rooms[*s].setType(dungeon::DUNGEON_NORMAL);
	}
	// Properly Define the room
	rooms[path[0]].setType(dungeon::DUNGEON_BEGIN);
	rooms[path[path.size() - 1]].setType(dungeon::DUNGEON_END);

	// For all rooms
	for (unsigned int i = 0; i < roomSize; i++) {
		// Generate Seed
		seed = i * DUNGEON_ROOM_MAX_HEIGHT * DUNGEON_ROOM_MAX_LENGTH;
		// Set random value for the colours
		clr = generateColour(seed);
		if (!isInPath(path, i)) {
			type = generateType(seed);
		}
		height = generateHeight(seed * 2);
		length = generateWidth(seed);
		rooms[i].createRoom(length, height, i, roomSize, type, clr);
	}
}

void dungeon::generateRooms(dungeon::Room* rooms, size_t roomSize, unsigned int pWidth, unsigned int pHeight, dungeonColour clr) {
	for (unsigned int i = 0; i < roomSize; i++) {
		rooms[i].createRoom(pWidth, pHeight, i, roomSize, dungeon::DUNGEON_NORMAL, clr);
	}
}

bool dungeon::isInPath(std::vector<size_t> path, size_t location) {
	for (unsigned int i = 0; i < path.size(); i++) {
		if (location == path[i]) {
			return true;
		}
	}
	return false;
}