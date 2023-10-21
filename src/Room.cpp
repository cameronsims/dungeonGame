#include "Room.hpp"
#include <string>

std::string* dungeon::Room::getRoom() {
	return this->roomData;
};

char dungeon::Room::getTile(size_t xPos, size_t yPos) {
	if (xPos >= this->length || yPos >= this->height) {
		return '\0';
	}
	printf("%c", this->roomData[yPos][xPos]);
	return this->roomData[yPos][xPos];
}

void dungeon::Room::createWalls(unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize) {
	this->fillHorizontalWall(pWidth, currentRoom, roomSize);
	this->fillVerticalWall(pHeight, currentRoom, roomSize);
	this->createDoors(pWidth, pHeight, currentRoom, roomSize);
}

void dungeon::Room::fillHorizontalWall(unsigned int pWidth, size_t currentRoom, size_t roomSize) {
	for (unsigned int i = 0; i < pWidth; i++) {					// For all x-positions
		this->roomData[0][i] = DUNGEON_WALL;					// Fill out top values of array
		this->roomData[pWidth - 1][i] = DUNGEON_WALL;			// Fill out lower values of array
		/*if ((pWidth / 2) <= i + 1 && (pWidth / 2) >= i - 1) {	// If we are in the middle of the wall
			if (!(currentRoom + roomSize - sqrt(roomSize) < roomSize)) {
				this->roomData[0][i] = ' ';							// Create a northern door
			}
			if (!(currentRoom + sqrt(roomSize) >= roomSize)) {
				this->roomData[pWidth - 1][i] = ' ';				// Create a southern door
			}
		}*/
	}
}
void dungeon::Room::fillVerticalWall(unsigned int pHeight, size_t currentRoom, size_t roomSize) {
	for (unsigned int i = 0; i < pHeight; i++) {				// For all y-positions
		this->roomData[i][0] = DUNGEON_WALL;					// Fill out left values of array
		this->roomData[i][pHeight - 1] = DUNGEON_WALL;			// Fill out right values of array
		/*if ((pHeight / 2) <= i + 1 && (pHeight / 2) >= i - 1) {	// If we are in the middle of the wall
			if (currentRoom % (int)sqrt(roomSize) != 0 &&		// If we are not on the far left-side of the dungeon
				currentRoom != 0) {
				this->roomData[i][0] = ' ';						// Create a western door
			}
			if ((currentRoom + 1) % (int)sqrt(roomSize) != 0 || // If we are not on the far right-side of the dungeon
				currentRoom == 0) {
				this->roomData[i][pHeight - 1] = ' ';			// Create a eastern door
			}
		}*/
	}
}

void dungeon::Room::createDoors(unsigned int pLength, unsigned int pHeight, size_t currentRoom, unsigned int roomSize) {
	bool divisibleByRoomLength = currentRoom % (int)sqrt(roomSize) == 0;
	for (int i = 0; i < pHeight; i++) {							// For all vertical values
		if ((pHeight / 2) <= i + 1 && (pHeight / 2) >= i - 1) {	// If we are in the middle of the wall
			if (!divisibleByRoomLength &&						// If we are not on the far left-side of the dungeon
				currentRoom != 0) {
				this->roomData[i][0] = DUNGEON_DOOR_VERTICAL;	// Create a western door
			}
			if ((currentRoom + 1) % (int)sqrt(roomSize) != 0 || // If we are not on the far right-side of the dungeon
				currentRoom == 0) {
				this->roomData[i][pHeight - 1] = DUNGEON_DOOR_VERTICAL;	// Create a eastern door
			}
		}
	}

	for (int i = 0; i < pLength; i++) {
		if ((pLength / 2) <= i + 1 && (pLength / 2) >= i - 1) {	// If we are in the middle of the wall
			if (!(currentRoom + roomSize - sqrt(roomSize) < roomSize)) {
				this->roomData[0][i] = DUNGEON_DOOR_HORIZONTAL;							// Create a northern door
			}
			if (!(currentRoom + sqrt(roomSize) >= roomSize)) {
				this->roomData[pLength - 1][i] = DUNGEON_DOOR_HORIZONTAL;				// Create a southern door
			}
		}
	}
}

unsigned int dungeon::Room::getLength() {
	return this->length;
}
unsigned int dungeon::Room::getHeight() {
	return this->height;
}

// Define Static vars
constexpr unsigned int dungeon::Room::xMax = 16;
constexpr unsigned int dungeon::Room::yMax = 16;