#pragma once

#include "Entity.hpp"

namespace dungeon {
	class Player : public Entity {
	private:
		void enterNewRoom(Room& room, ENTITIES& entities, size_t roomSize, size_t newRoom);
		void setMiddleVertical(Room& room);
		void setMiddleHorizontal(Room& room);

		void moveRight(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveLeft(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveUp(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveDown(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
	public:
		Player(unsigned int pX, unsigned int pY, unsigned int pRoom) {
			this->createEntity('P', pX, pY, pRoom, ENTITY_PLAYER);
		}
		Player(Entity& const ent)  {
			this->createEntity(ent);
		}

		void move(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities, Movement move);
	};
}