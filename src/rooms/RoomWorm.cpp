#pragma once

#include "RoomWorm.hpp"

#include "../random/Random.hpp"

#include <cmath>

std::vector<size_t> dungeon::Worm::getPath() const {
	return this->previouslyExplored;
}

size_t dungeon::Worm::nextRoom() {
	const unsigned int roomSize = this->width * this->height;
	Slither slither = (Worm::Slither)dungeon::generateNumber<unsigned int>(SLITHER_UP, SLITHER_DOWN, roomSize);;
	int movement[4] = { -(int)this->width, -1, 1, this->width};
	// If we've already been in:
	if (this->hasBeenIn(this->currentRoom + movement[slither])) {
		// Go through all iterations
		for (int i = SLITHER_UP; i < SLITHER_DOWN + 1; i++) {
			// If we can go in a room
			if (!this->hasBeenIn(this->currentRoom + movement[i]) && this->canGoIn(this->currentRoom, this->currentRoom + movement[i])) {
				slither = (Worm::Slither)i;
			}
		}
	}
	// Change the rooms
	this->currentRoom += movement[slither];
	this->previouslyExplored.push_back(this->currentRoom);

	return this->currentRoom;
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
	bool adjacent = (floor((oriRoom / this->width)) == floor(newRoom / this->width)) ||	// If ón the same row
					(fmax(oriRoom, newRoom) - fmin(oriRoom, newRoom) == this->width); // If on same collumn
	return (newRoom < this->width * this->height) && adjacent;
}


void dungeon::Worm::start() {
	// Get the amount of jumps we will do
	unsigned int amount = dungeon::generateNumber<unsigned int>(this->minMoves, this->maxMoves, this->minMoves * this->maxMoves);
	// Iterate over
	while (amount) {
		this->nextRoom();
		amount--;
	}
}

size_t dungeon::Worm::getRoom() const {
	return this->currentRoom;
}

dungeon::Worm::Worm(size_t pOrigin, unsigned int pWidth, unsigned pHeight) : currentRoom(pOrigin), width(pWidth), height(pHeight) {
	// Add current Room
	this->previouslyExplored.push_back(currentRoom);
	// Ensure the worm doesn't terminate immidently
	this->minMoves = (fmax(width, height) + 1);
	this->maxMoves = (width * height - 2 * fmin(width, height));
}
dungeon::Worm::~Worm() {

}