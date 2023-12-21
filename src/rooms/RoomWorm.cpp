#include "RoomWorm.hpp"

#include "../random/Random.hpp"
#include "Dungeon.hpp"

#include <cmath>

std::vector<size_t> dungeon::Worm::getPath() const {
	return this->previouslyExplored;
}

size_t dungeon::Worm::nextRoom() {
	const int movement[SLITHER_DOWN + 1] = { -(int)this->dun->getWidth(), -1, 1, (int)(this->dun->getWidth())};

	Slither proj = SLITHER_NONE;

	std::vector<Slither> potRooms;
	// Check all potential movement
	for (unsigned int i = 0; i < SLITHER_DOWN + 1; i++) {
		// Set projection
		proj = (Slither)i;
		// Check if we've been in the room
		if (this->tryRoom(movement, this->currentRoom, proj)) {
			// Add a new room to list of potential rooms
			potRooms.push_back(proj);
		}
	}

	if (potRooms.size() > 1) {
		proj = potRooms[generateNumber<unsigned int>(0, potRooms.size() - 1, potRooms.size()* this->dun->size())];
	} else {
		proj = SLITHER_RIGHT;
	}

	this->currentRoom = this->currentRoom + movement[proj];

	return this->currentRoom;
}

bool dungeon::Worm::tryRoom(const int* const movement, size_t ogRoom, Slither proj) const {
	bool goUpLimit = (this->currentRoom < this->dun->getWidth()) && proj == SLITHER_UP,
		 goDownLimit = (this->currentRoom >= this->dun->size() - this->dun->getWidth()) && proj == SLITHER_DOWN;

	return (
		!this->hasBeenIn(ogRoom + movement[proj]) &&
		this->canGoIn(ogRoom, ogRoom + movement[proj]) &&
		!(goUpLimit || goDownLimit));

}

bool dungeon::Worm::hasBeenIn(size_t newRoom) const {
	for (const size_t& s : this->previouslyExplored) {
		if (s == newRoom) {
			return true;
		}
	}
	return false;
}

bool dungeon::Worm::canGoIn(size_t oriRoom, size_t newRoom) const {
	bool adjVertical = ((newRoom == oriRoom - this->dun->getWidth()) || (newRoom == oriRoom + this->dun->getWidth())),
		 adjHorizontal = ((newRoom == oriRoom + 1) || (newRoom == oriRoom - 1)) &&
						 (int)floor(newRoom/ this->dun->getWidth()) == (int)floor(oriRoom / this->dun->getWidth());

	return (newRoom < this->dun->size()) && (adjVertical || adjHorizontal);
}


void dungeon::Worm::start() {
	// Get the amount of jumps we will do
	unsigned int amount = dungeon::generateNumber<unsigned int>(this->minMoves, this->maxMoves, this->minMoves * this->maxMoves);
	// Iterate over
	for (unsigned int i = 0; i < amount; i++) {
		this->previouslyExplored.push_back(this->nextRoom());
	}
}

size_t dungeon::Worm::getRoom() const {
	return this->currentRoom;
}

dungeon::Worm::Worm(size_t pOrigin, Dungeon* const pDungeon) : currentRoom(pOrigin), dun(pDungeon) {
			// Add current Room
	this->previouslyExplored.push_back(currentRoom);
	// Ensure the worm doesn't terminate immidently
	this->minMoves = (fmax(dun->getWidth(), dun->getHeight()) + 1);
	this->maxMoves = 2 * this->minMoves;
}