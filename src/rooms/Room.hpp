#pragma once

#include <string>

#include "DungeonMeta.hpp"

namespace dungeon {

	class Room {
		friend void generateRooms(dungeon::Room* rooms, unsigned int width, unsigned int height, size_t roomSize);
		friend void generateRooms(dungeon::Room* rooms, unsigned int width, unsigned int height, size_t roomSize, dungeonColour clr);
	private:
		std::string* roomData;

		dungeonColour mode;

		dungeonType type;

		unsigned int length = 0;
		unsigned int height = 0;

		void fillHorizontalWall(unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize);
		void fillVerticalWall(unsigned int pWidth, unsigned int pHeight, size_t currentRoom, size_t roomSize);
	public:
		static bool onEdge(size_t currentRoom, size_t roomSize);

		static unsigned int roomAbove(size_t currentRoom, size_t roomSize);
		static unsigned int roomBelow(size_t currentRoom, size_t roomSize);

		bool exists();

		std::string* getRoom();
		dungeonColour getMode();
		char getTile(size_t xPos, size_t yPos);

		unsigned int getLength();
		unsigned int getHeight();

		dungeonType getType();
		dungeonType setType(dungeon::dungeonType pType);

		unsigned int getRoomHex();

		void createWalls(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize);
		void createDoors(unsigned int pLength, unsigned int pHeight, size_t currentRoom, unsigned int roomSize);

		void createRoom(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize, dungeonType pType, dungeonColour pMode);

		// Create room
		Room();
		Room(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize, dungeonType pType, dungeonColour pMode);
		~Room();
	};
}