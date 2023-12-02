#pragma once

#include "../rooms/DungeonMeta.hpp"
#include "../rooms/Room.hpp"

namespace dungeon {
	void refreshSeed(unsigned int pSeed);

	template<typename T>
	T generateNumber(T lower, T higher, unsigned int pSeed = 1);

	dungeon::dungeonColour generateColour(unsigned int pSeed);
	unsigned int generateWidth(unsigned int pSeed);
	unsigned int generateHeight(unsigned int pSeed);
	dungeon::dungeonType generateType(unsigned int pSeed);
}