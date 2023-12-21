#include "EntityGenerator.hpp"

#include "Dungeon.hpp"
#include "../random/Random.hpp"
#include "../entities/Entity.hpp"
#include "../entities/Enemy.hpp"

#include "../io/Files.hpp"

size_t dungeon::enemyAmountInRoom(const std::vector<dungeon::Entity>& pEntities, const dungeon::Dungeon* const dungeon, size_t room) {
	size_t amount = 0;
	for (const dungeon::Entity& const e : pEntities) {
		if (e.getRoom() == room && e.getBehaviour() != dungeon::ENTITY_PLAYER) {
			amount++;
		}
	}
	return amount;
}

size_t dungeon::generateEnemyAmount(const dungeon::Dungeon* const dungeon) {

	const unsigned int seed = dungeon->size();

	const size_t amount = dungeon::generateNumber<unsigned int>(dungeon->size(), DUNGEON_ENEMY_MAX, seed);

	if (dungeon->size() >= DUNGEON_ENEMY_MAX) {
		return DUNGEON_ENEMY_MAX;
	} 

	return amount;
}

void dungeon::generateEnemies(const dungeon::Dungeon* const dungeon, std::vector<dungeon::Entity>& pEntities, dungeon::Entity& const player) {
	// Get an amount of enemies
	const size_t amount = dungeon::generateEnemyAmount(dungeon);
	dungeon::Room* const rooms = dungeon->getRooms();

	// Get the rooms that aren't empty
	std::vector<unsigned int> applicableRooms;
	for (size_t i = 0; i < dungeon->size(); i++) {
		// If room exists, add it to the vector
		if (rooms[i].exists() && player.getRoom() != i) {
			applicableRooms.push_back(i);
		}
	}

	// Loop for amount of entities we are creating
	for (size_t i = 0; i < amount; i++) {
		// Make a new seed
		const size_t seed = i * dungeon->size();

		// Create behaviour and stuff
		dungeon::EntityBehaviour behaviour = (dungeon::EntityBehaviour)dungeon::generateNumber<unsigned int>(dungeon::ENEMY_FOLLOW, dungeon::ENEMY_VERTICAL, seed);
		
		// Find a room to put this enemy in that has under a certain amount of enemies
		unsigned int room = dungeon::generateNumber<unsigned int>(0, applicableRooms.size() - 1, seed),
					 x = 0, 
					 y = 0;
		
		while (std::find(applicableRooms.begin(), applicableRooms.end(), room) == applicableRooms.end()) {
			// Gather the amount of entities in a room
			unsigned int amount = 0;
			// Generate a new number
			room = dungeon::generateNumber<unsigned int>(0, applicableRooms.size() - 1, seed);
			// If it's not good enough, iterate over
			if (std::find(applicableRooms.begin(), applicableRooms.end(), room) == applicableRooms.end()) {
				if (room >= dungeon->size()) {
					room = 0;
				} else {
					room++;
				}
			}
		}

		// Room where the entity is
		dungeon::Room* const selectedRoom = &(rooms[room]);

		// Set Coordinates
		x = dungeon::generateNumber<unsigned int>(1, selectedRoom->getLength() - 2, seed);
		y = dungeon::generateNumber<unsigned int>(1, selectedRoom->getHeight() - 2, seed);

		// Create a new enemy, in the entity vector
		pEntities.push_back(dungeon::Enemy(x, y, room, behaviour));
	}

	// Change the player reference
	player = pEntities[0];
}

void dungeon::setEnemies(std::vector<dungeon::Enemy*>& enemies, const std::vector<dungeon::Entity>& const entities) {
	for (const dungeon::Entity& e : entities) {
		if (e.getBehaviour() != dungeon::ENTITY_PLAYER) {
			enemies.push_back((dungeon::Enemy*)&e);
		}
	}
}