#pragma once

#include <string>

#include "DungeonMeta.hpp"

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

		dungeonColour mode;

		unsigned int length = 0;
		unsigned int height = 0;

		void fillHorizontalWall(unsigned int pWidth, size_t currentRoom, size_t roomSize);
		void fillVerticalWall(unsigned int pHeight, size_t currentRoom, size_t roomSize);
	public:
		std::string* getRoom();
		dungeonColour getMode();
		char getTile(size_t xPos, size_t yPos);

		unsigned int getLength();
		unsigned int getHeight();

		unsigned int getRoomHex();

		void createWalls(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize);
		void createDoors(unsigned int pLength, unsigned int pHeight, size_t currentRoom, unsigned int roomSize);

		void createRoom(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize, dungeonColour pMode);

		// Create room
		Room() {
			this->createRoom(7, 7, 0, 4, DUNGEON_DEFAULT);
		}
		Room(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize, dungeonColour pMode) {
			this->createRoom(pLength, pHeight, currentRoom, roomSize, pMode);
		}

		~Room() {
			delete[] roomData;
		}
	};
}