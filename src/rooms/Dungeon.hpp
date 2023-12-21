#pragma once

#include "Room.hpp"

namespace dungeon {
	class Dungeon {
	  private:
		size_t width, height;
		dungeon::Room* rooms;
	  public:
		size_t size() const;
		size_t getWidth() const;
		size_t getHeight() const;

		dungeon::Room* getRooms() const;

		Dungeon(dungeon::Room* pRooms, size_t pWidth, size_t pHeight);
	};
}