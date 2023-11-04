#include "RoomGenerator.hpp"
#include "Room.hpp"

namespace dungeon {
	void generateRooms(dungeon::Room* rooms, unsigned int width, unsigned int height, size_t roomSize, dungeonColour clr) {
		for (int i = 0; i < roomSize; i++) {
			rooms[i].createRoom(width, height, i, roomSize, clr);
		}
	}
}