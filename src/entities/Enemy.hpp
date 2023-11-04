#pragma once

#include "Entity.hpp"

namespace dungeon {
	class Enemy : public Entity {
	public:

		void update(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);

		Enemy(char pIcon, unsigned int pX, unsigned int pY, unsigned int pRoom, EntityBehaviour pBehave) {
			this->createEntity(pIcon, pX, pY, pRoom, pBehave);
		}
		Enemy(Entity ent) {
			this->createEntity(ent);
		}
	};
}