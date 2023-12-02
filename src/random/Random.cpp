#include "Random.hpp"

#include <random>
#include <ctime>

void dungeon::refreshSeed(unsigned int pSeed) {
	srand(pSeed * time(NULL));
}

template<typename T>
T dungeon::generateNumber(T lower, T higher, unsigned int pSeed) {
	// Give Random Seed
	refreshSeed(pSeed);
	// Generate the number
	return (T)(rand() % higher + lower);
}

dungeon::dungeonColour dungeon::generateColour(unsigned int pSeed) {
	// Set random value for the colours
	return dungeon::generateNumber<dungeon::dungeonColour>((dungeon::dungeonColour)0, (dungeon::dungeonColour)(dungeon::dungeonAmounts - 1), pSeed);
}

unsigned int dungeon::generateWidth(unsigned int pSeed) {
	return dungeon::generateNumber<unsigned int>(DUNGEON_ROOM_MIN_LENGTH, DUNGEON_ROOM_MAX_LENGTH, pSeed);
}

unsigned int dungeon::generateHeight(unsigned int pSeed) {
	return dungeon::generateNumber<unsigned int>(DUNGEON_ROOM_MIN_HEIGHT, DUNGEON_ROOM_MAX_HEIGHT, pSeed);
}

dungeon::dungeonType dungeon::generateType(unsigned int pSeed) {
	unsigned int number = dungeon::generateNumber<unsigned int>(0, 100, pSeed);
	dungeonType type = (dungeonType)((number < 20)*DUNGEON_EMPTY + (number >= 20)*dungeon::DUNGEON_NORMAL);
	return type;
}