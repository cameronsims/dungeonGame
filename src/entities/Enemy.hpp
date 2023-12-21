#pragma once

#include "Entity.hpp"

namespace dungeon {
	class Enemy : public Entity {
	public:

		void update(dungeon::Room* rooms, size_t roomSize, dungeon::Entity* const player, ENTITIES& entities);

		Enemy(char pIcon, unsigned int pX, unsigned int pY, unsigned int pRoom, EntityBehaviour pBehave);
		Enemy(unsigned int pX, unsigned int pY, unsigned int pRoom, EntityBehaviour pBehave);
		Enemy(Entity ent);
	};
}