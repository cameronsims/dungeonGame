#pragma once

#include <vector>
#include "../random/Random.hpp"

namespace dungeon {
	class Worm {
	  private:
		  const static enum Slither {
			  SLITHER_UP = 0,
			  SLITHER_LEFT,
			  SLITHER_RIGHT,
			  SLITHER_DOWN
		  };

		  std::vector<size_t> previouslyExplored;
		  size_t currentRoom;

		  unsigned int minMoves, maxMoves;

		  const unsigned int width, height;

		  size_t nextRoom();
	  public:
		std::vector<size_t> getPath() const;
		bool hasBeenIn(size_t newRoom) const;
		bool canGoIn(size_t oriRoom, size_t newRoom) const;

		void start();

		size_t getRoom() const;

		Worm(size_t pOrigin, unsigned int pWidth, unsigned pLength);
		~Worm();
	};
}