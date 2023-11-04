#pragma once

#include "Entity.hpp"

namespace dungeon {
	class Player : public Entity {
	public:
		Player(unsigned int pX, unsigned int pY, unsigned int pRoom) {
			this->createEntity('P', pX, pY, pRoom, ENTITY_PLAYER);
		}
		Player(Entity& const ent)  {
			this->createEntity(ent);
		}

		void moveRight(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveLeft(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveUp(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveDown(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
	};
}