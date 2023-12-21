#include "RoomGenerator.hpp"

#include "DungeonMeta.hpp"
#include "Dungeon.hpp"
#include "Room.hpp"
#include "../random/Random.hpp"

#include <vector>

void dungeon::generateRooms(dungeon::Room* rooms, dungeon::Dungeon& d, std::vector<size_t> path) {
	dungeon::dungeonColour clr;
	dungeon::dungeonType* type = new dungeon::dungeonType[d.size()];
	unsigned int height, length, seed;

	// First we need to generate ALL of the types of rooms, so we can properly lock certain rooms off 
	for (unsigned int i = 0; i < d.size(); i++) {
		// If it's in the path, then define it as normal (besides start and end)
		if (dungeon::isInPath(path, i)) {
			type[i] = dungeon::DUNGEON_NORMAL;
		} 
		// Otherwise, then randomly generate it
		else {
			type[i] = dungeon::generateType(i);
		}
	}

	// Properly Define the room's entry and exit (overwrites last step)
	type[path[0]] = dungeon::DUNGEON_BEGIN;
	type[path[path.size() - 1]] = dungeon::DUNGEON_END;

	// For all rooms
	for (unsigned int i = 0; i < d.size(); i++) {
		// Generate Seed
		seed = i * DUNGEON_ROOM_MAX_HEIGHT * DUNGEON_ROOM_MAX_LENGTH;
		// Set random value for the colours
		clr = dungeon::generateColour(seed);
		height = dungeon::generateHeight(seed * 2);
		length = dungeon::generateWidth(seed);

		createRoom(rooms[i], length, height, i, d, type, clr);
	}

	// Remove from stack
	delete[] type;
}

bool dungeon::isInPath(std::vector<size_t> path, size_t location) {
	for (unsigned int i = 0; i < path.size(); i++) {
		if (location == path[i]) {
			return true;
		}
	}
	return false;
}

void dungeon::createRoom(dungeon::Room& pRoom, unsigned int pLength, unsigned int pHeight, size_t currentRoom, dungeon::Dungeon& d, dungeonType* pTypes, dungeonColour pMode) {
	if (pTypes[currentRoom] == DUNGEON_EMPTY) {
		pLength = 0;
		pHeight = 0;
		pMode = dungeon::DUNGEON_DEFAULT;
	}

	pRoom.setLength(pLength);
	pRoom.setHeight(pHeight);
	pRoom.setMode(pMode);
	pRoom.setType(pTypes[currentRoom]);
	pRoom.setRoom(pHeight, pLength);

	if (pTypes[currentRoom] != DUNGEON_EMPTY) {
		createWalls(pRoom, pLength, pHeight, pTypes, currentRoom, d);		// Create walls
	}
}


void dungeon::fillHorizontalWall(Room& pRoom, unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize) {
	const unsigned int right = pWidth - 1;
	// Fill out top and bottom
	for (int i = 1; i < pHeight - 1; i++) {
		pRoom.setTile(0, i, DUNGEON_WALL);
		pRoom.setTile(right, i, DUNGEON_WALL);
	}
}
void dungeon::fillVerticalWall(Room& pRoom, unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize) {
	for (unsigned int i = 0; i < pWidth; i++) {		// For all y-positions
		pRoom.setTile(i, 0, DUNGEON_WALL);
		pRoom.setTile(i, pHeight - 1, DUNGEON_WALL);
	}
}
void dungeon::createDoors(Room& pRoom, unsigned int pLength, unsigned int pHeight, dungeon::dungeonType* pTypes, size_t currentRoom, dungeon::Dungeon& d) {
	const size_t& dungeonWidth = d.getWidth();

	bool divisibleByRoomLengthWest = currentRoom % dungeonWidth == 0;
	bool divisibleByRoomLengthEast = (currentRoom + 1) % dungeonWidth == 0;

	bool drawWest = (!divisibleByRoomLengthWest &&							// If we are not on the far left-side of the dungeon
					 currentRoom != 0 &&									// AND we are NOT in position 0
					 pTypes[currentRoom - 1] != DUNGEON_EMPTY);				// AND if there is a room which isn't empty

	bool drawNorth = ((currentRoom > dungeonWidth - 1) &&
					  pTypes[currentRoom - dungeonWidth] != DUNGEON_EMPTY);

	bool drawEast = (!divisibleByRoomLengthEast &&
					 pTypes[currentRoom + 1] != DUNGEON_EMPTY);

	bool drawSouth = (currentRoom < (d.size() - d.getWidth()) &&
					  pTypes[currentRoom + dungeonWidth] != DUNGEON_EMPTY);

	for (int i = 0; i < pHeight; i++) {							// For all vertical values
		if ((pHeight / 2) <= i + 1 && (pHeight / 2) >= i - 1) {	// If we are in the middle of the wall
			if (drawWest) {
				pRoom.setTile(0, i, DUNGEON_DOOR_VERTICAL);
			}
			if (drawEast) {
				pRoom.setTile(pLength - 1, i, DUNGEON_DOOR_VERTICAL);
			}
		}
	}

	for (int i = 0; i < pLength; i++) {
		if ((pLength / 2) <= i + 1 && (pLength / 2) >= i - 1) {	// If we are in the middle of the wall
			if (drawNorth) {
				pRoom.setTile(i, 0, DUNGEON_DOOR_HORIZONTAL);
			}
			if (drawSouth) {
				pRoom.setTile(i, pHeight - 1, DUNGEON_DOOR_HORIZONTAL);
			}
		}
	}
}
void dungeon::createWalls(Room& pRoom, unsigned int pWidth, unsigned int pHeight, dungeon::dungeonType* pTypes, size_t currentRoom, dungeon::Dungeon& d) {
	fillHorizontalWall(pRoom, pWidth, pHeight, currentRoom, d.size());
	fillVerticalWall(pRoom, pWidth, pHeight, currentRoom, d.size());
	createDoors(pRoom, pWidth, pHeight, pTypes, currentRoom, d);
}