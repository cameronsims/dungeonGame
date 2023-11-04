#include "Enemy.hpp"

#include <iostream>

void dungeon::Enemy::update(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities) {
	// Behaviour goes here
	const unsigned int xPos = this->getX(),
					   yPos = this->getY();
	// The room that this entity is in now
	dungeon::Room& room = rooms[this->getRoom()];
	// Dictate Behaviour
	switch (this->behaviour) {
		// If the Enemy is a player or still
		default: { return; }
		// Enemy Moves Vertical
		case dungeon::ENEMY_VERTICAL: {
			// If we are at either bounds
			if (this->getY() <= 1 || this->getY() >= room.getHeight() - 2) {
				this->speed = -this->speed;
			}
			if (this->speed >= 0) {
				// If the entity can move
				this->moveUp(rooms, roomSize, entities);
				return;
			}
			this->moveUp(rooms, roomSize, entities);
			return;
		}
		// Enemy moves Horizontal
		case dungeon::ENEMY_HORIZONTAL: {
			// If we are at either bounds
			if (this->getX() <= 1 || this->getX() >= room.getLength() - 2) {
				this->speed = -this->speed;
			}
			if (this->speed >= 0) {
				// If the entity can move
				this->moveRight(rooms, roomSize, entities);
				return;
			}
			this->moveRight(rooms, roomSize, entities);
			return;
		}
	}
}