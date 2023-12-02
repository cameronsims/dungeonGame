#include "Room.hpp"

#include <string>

bool dungeon::Room::onEdge(size_t currentRoom, size_t roomSize) {
	return (currentRoom + 1) % (int)sqrt(roomSize) == 0;
}
unsigned int dungeon::Room::roomAbove(size_t currentRoom, size_t roomSize) {
	return currentRoom - sqrt(roomSize);
}
unsigned int dungeon::Room::roomBelow(size_t currentRoom, size_t roomSize) {
	return currentRoom + sqrt(roomSize);
}

bool dungeon::Room::exists() {
	return (this->length <= 0) || (this->height <= 0) || (this->type == DUNGEON_EMPTY);
}

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
	this->fillHorizontalWall(pWidth, pHeight, currentRoom, roomSize);
	this->fillVerticalWall(pWidth, pHeight, currentRoom, roomSize);
	this->createDoors(pWidth, pHeight, currentRoom, roomSize);
}

void dungeon::Room::fillHorizontalWall(unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize) {
	for (unsigned int i = 0; i < pWidth; i++) {					// For all x-positions
		this->roomData[0][i] = DUNGEON_WALL;					// Fill out top values of array
		this->roomData[pHeight - 1][i] = DUNGEON_WALL;			// Fill out lower values of array
	}
}
void dungeon::Room::fillVerticalWall(unsigned int pWidth,unsigned int pHeight, size_t currentRoom, size_t roomSize) {
	for (unsigned int i = 0; i < pHeight; i++) {				// For all y-positions
		this->roomData[i][0] = DUNGEON_WALL;					// Fill out left values of array
		this->roomData[i][pWidth - 1] = DUNGEON_WALL;			// Fill out right values of array
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
				this->roomData[i][pLength - 1] = DUNGEON_DOOR_VERTICAL;	// Create a eastern door
			}
		}
	}

	for (int i = 0; i < pLength; i++) {
		if ((pLength / 2) <= i + 1 && (pLength / 2) >= i - 1) {	// If we are in the middle of the wall
			if (!(currentRoom + roomSize - sqrt(roomSize) < roomSize)) {
				this->roomData[0][i] = DUNGEON_DOOR_HORIZONTAL;			 // Create a northern door
			}															 
			if (!(currentRoom + sqrt(roomSize) >= roomSize)) {			 
				this->roomData[pHeight - 1][i] = DUNGEON_DOOR_HORIZONTAL; // Create a southern door
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

unsigned int dungeon::Room::getRoomHex() {
	// Colour code of console [Hex value from 00 -> FF]
	return 0x01*dungeon::dungeonColourMap[this->mode][0] + 0x10*dungeon::dungeonColourMap[this->mode][1];
};

dungeon::dungeonType dungeon::Room::getType() {
	return this->type;
}
dungeon::dungeonType dungeon::Room::setType(dungeon::dungeonType pType) {
	this->type = pType;
	return this->type;
}

void dungeon::Room::createRoom(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize, dungeonType pType, dungeonColour pMode) {
	if (pType == DUNGEON_EMPTY) {
		pLength = 0;
		pHeight = 0;
		pMode = dungeon::DUNGEON_DEFAULT;
	}
	this->length = pLength;
	this->height = pHeight;
	this->mode = pMode;
	this->type = pType;
	roomData = new std::string[pHeight];				// Initalise Room Contents to empty string
	for (unsigned int i = 0; i < pHeight; i++) {		// For every single vertical value
		for (unsigned int j = 0; j < pLength; j++) {	// For every single horizontal character
			roomData[i].push_back(DUNGEON_CLEAR);		// Set an invalid value
		}
		roomData[i].push_back('\0');
	}
	if (pType != DUNGEON_EMPTY) {
		this->createWalls(pLength, pHeight, currentRoom, roomSize);		// Create walls
	}
}

dungeon::dungeonColour dungeon::Room::getMode() {
	return this->mode;
}

dungeon::Room::Room() {
	this->createRoom(7, 7, 0, 4, DUNGEON_NORMAL, DUNGEON_DEFAULT);
}
dungeon::Room::Room(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize, dungeonType pType, dungeonColour pMode) {
	this->createRoom(pLength, pHeight, currentRoom, roomSize, pType, pMode);
}

dungeon::Room::~Room() {
	delete[] roomData;
}