#pragma once

#include <string>

#define DUNGEON_EMPTY ' '
#define DUNGEON_WALL '#'
#define DUNGEON_DOOR_HORIZONTAL '-'
#define DUNGEON_DOOR_VERTICAL '|'

namespace dungeon {

	class Room {
	private:
		std::string* roomData;
		const static unsigned int xMax;
		const static unsigned int yMax;

		unsigned int length = 0;
		unsigned int height = 0;

		void fillHorizontalWall(unsigned int pWidth, size_t currentRoom, size_t roomSize);
		void fillVerticalWall(unsigned int pHeight, size_t currentRoom, size_t roomSize);
	public:
		std::string* getRoom();
		char getTile(size_t xPos, size_t yPos);

		unsigned int getLength();
		unsigned int getHeight();

		void createWalls(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize);
		void createDoors(unsigned int pLength, unsigned int pHeight, size_t currentRoom, unsigned int roomSize);

		// Create room
		Room(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize) : length(pLength), height(pHeight) {
			roomData = new std::string[pHeight];				// Initalise Room Contents to empty string
			for (unsigned int i = 0; i < pHeight; i++) {		// For every single vertical value
				roomData[i] = "";								// Set string to values
				for (unsigned int j = 0; j < pLength; j++) {	// For every single horizontal character
					roomData[i].push_back(DUNGEON_EMPTY);		// Set an invalid value
				}
			}
			this->createWalls(length, height, currentRoom, roomSize);		// Create walls
		}

		~Room() {
			delete[] roomData;
		}
	};
}