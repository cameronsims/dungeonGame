#pragma once

#include "Dungeon.hpp"

#include <vector>

namespace dungeon {
	class Worm {
	  protected:
		const static enum Slither {
			SLITHER_NONE = -1,
			SLITHER_UP = 0,
			SLITHER_LEFT,
			SLITHER_RIGHT,
			SLITHER_DOWN,
		};
	  private:
		std::vector<size_t> previouslyExplored;
		size_t currentRoom;

		unsigned int minMoves, maxMoves;
		const dungeon::Dungeon* const dun = nullptr;

		size_t nextRoom();
		bool tryRoom(const int* const movement, size_t ogRoom, Worm::Slither proj) const;
	  public:
		std::vector<size_t> getPath() const;
		size_t getRoom() const;

		bool hasBeenIn(size_t newRoom) const;
		bool canGoIn(size_t oriRoom, size_t newRoom) const;

		void start();

		// Has to be in here???
		Worm(size_t pOrigin, Dungeon* const pDungeon);
	};
}