#pragma once

#include "Entity.hpp"

namespace dungeon {
	class Player : public Entity {
	public:
		Player(unsigned int pX, unsigned int pY, unsigned int pRoom) {
			this->icon = 'P';
			this->x = pX;
			this->y = pY;
			this->currentRoom = pRoom;
		}
		Player(Entity ent)  {
			this->icon = 'P';
			this->x = ent.getX();
			this->y = ent.getY();
			this->currentRoom = ent.getRoom();
		}

		void moveRight(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
		void moveLeft(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
		void moveUp(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
		void moveDown(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
	};
}