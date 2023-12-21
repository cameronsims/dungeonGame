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

bool dungeon::Room::exists() const {
	return ((this->length > 0) || (this->height > 0)) && (this->type != DUNGEON_EMPTY);
}

std::string* dungeon::Room::getRoom() const {
	return this->roomData;
};
std::string* dungeon::Room::setRoom(size_t pHeight, size_t pLength) {
	roomData = new std::string[pHeight];				// Initalise Room Contents to empty string
	for (unsigned int i = 0; i < pHeight; i++) {		// For every single vertical value
		for (unsigned int j = 0; j < pLength; j++) {	// For every single horizontal character
			roomData[i].push_back(DUNGEON_CLEAR);		// Set an invalid value
		}
		roomData[i].push_back('\0');
	}
	return this->roomData;
}

char dungeon::Room::getTile(size_t xPos, size_t yPos) const {
	if (xPos >= this->length || yPos >= this->height) {
		return '\0';
	}
	return this->roomData[yPos][xPos];
}
char dungeon::Room::setTile(size_t xPos, size_t yPos, char c) {
	this->roomData[yPos][xPos] = c;
	return this->roomData[yPos][xPos];
}

unsigned int dungeon::Room::getLength() const {
	return this->length;
}
unsigned int dungeon::Room::setLength(unsigned int pLength) {
	this->length = pLength;
	return this->length;
}

unsigned int dungeon::Room::getHeight() const {
	return this->height;
}
unsigned int dungeon::Room::setHeight(unsigned int pHeight) {
	this->height = pHeight;
	return  this->height;
}

unsigned int dungeon::Room::getRoomHex() {
	// Colour code of console [Hex value from 00 -> FF]
	return 0x01*dungeon::dungeonColourMap[this->mode][0] + 0x10*dungeon::dungeonColourMap[this->mode][1];
};

dungeon::dungeonType dungeon::Room::getType() const {
	return this->type;
}
dungeon::dungeonType dungeon::Room::setType(dungeon::dungeonType pType) {
	this->type = pType;
	return this->type;
}

dungeon::dungeonColour dungeon::Room::getMode() const {
	return this->mode;
}
dungeon::dungeonColour dungeon::Room::setMode(dungeon::dungeonColour pColour) {
	this->mode = pColour;
	return this->mode;
}

dungeon::Room::Room() { }
dungeon::Room::~Room() {
	delete[] roomData;
}