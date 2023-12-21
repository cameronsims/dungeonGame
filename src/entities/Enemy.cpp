#include "Enemy.hpp"

#include <iostream>

void dungeon::Enemy::update(dungeon::Room* rooms, size_t roomSize, dungeon::Entity* const player, ENTITIES& entities) {
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

		case dungeon::ENEMY_FOLLOW: {
			// Where we are moving
			bool moveLeft = (player->getX() < this->getY()),
				 moveRight = (player->getX() > this->getX()),
				 moveUp = (player->getY() < this->getY()),
				 moveDown = (player->getY() > this->getY());

			unsigned int vertical = moveLeft + 2*moveRight,	// 0 = Still, 1 = Left, 2 = Right
						 horizontal = moveUp + 2*moveDown;	// 0 = Still, 1 = Up,   2 = Down

			switch (vertical) {
				default: { break; }
				case 1: { this->moveLeft(rooms, roomSize, entities); break; }
				case 2: { this->moveRight(rooms, roomSize, entities); break; }
			}

			switch (horizontal) {
				default: { break; }
				case 1: { this->moveUp(rooms, roomSize, entities); break; }
				case 2: { this->moveDown(rooms, roomSize, entities); break; }
			}
		}
	}
}

dungeon::Enemy::Enemy(char pIcon, unsigned int pX, unsigned int pY, unsigned int pRoom, EntityBehaviour pBehave) {
	this->createEntity(pIcon, pX, pY, pRoom, pBehave);
}

dungeon::Enemy::Enemy(unsigned int pX, unsigned int pY, unsigned int pRoom, EntityBehaviour pBehave) {
	this->createEntity('E', pX, pY, pRoom, pBehave);
}

dungeon::Enemy::Enemy(Entity ent) {
	this->createEntity(ent);
}