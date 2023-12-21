#pragma once

#include "DungeonMeta.hpp"

#include <string>

namespace dungeon {

	class Room {
	private:
		std::string* roomData;

		dungeonColour mode;

		dungeonType type;

		unsigned int length = 0;
		unsigned int height = 0;
	public:
		static bool onEdge(size_t currentRoom, size_t roomSize);

		static unsigned int roomAbove(size_t currentRoom, size_t roomSize);
		static unsigned int roomBelow(size_t currentRoom, size_t roomSize);

		bool exists() const;

		std::string* getRoom() const;
		std::string* setRoom(size_t pHeight, size_t pLength);

		dungeonColour getMode() const;
		dungeonColour setMode(dungeonColour pColour);

		char getTile(size_t xPos, size_t yPos) const;
		char setTile(size_t xPos, size_t yPos, char c);

		unsigned int getLength() const;
		unsigned int setLength(unsigned int pLength);
		unsigned int getHeight() const;
		unsigned int setHeight(unsigned int pHeight);

		dungeonType getType() const;
		dungeonType setType(dungeon::dungeonType pType);

		unsigned int getRoomHex();

		// Create room
		Room();
		//Room(unsigned int pLength, unsigned int pHeight, size_t currentRoom, size_t roomSize, dungeonType pType, dungeonColour pMode);
		~Room();
	};
}