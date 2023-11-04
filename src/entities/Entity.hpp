#pragma once

#include <vector>

#include "../rooms/Room.hpp"

#define ENTITIES std::vector<dungeon::Entity*>

namespace dungeon {
	enum EntityBehaviour {
		ENTITY_PLAYER = 0,
		ENTITY_STILL,
		ENEMY_FOLLOW,
		ENEMY_HORIZONTAL,
		ENEMY_VERTICAL
	};

	enum EntityFacing {
		ENTITY_NORTH = 0,
		ENTITY_WEST,
		ENTITY_EAST,
		ENTITY_SOUTH
	};

	class Entity {
	protected:
		unsigned int x;				// Horizontal Location (From the left)
		unsigned int y;				// Vertical Location (From the top)
		int baseSpeed = 1;			// Speed by default
		int speed = 1;				// Speed is mutliplied by 1 (base speed).

		EntityBehaviour behaviour;	// Behaviour the Entity will undergo

		unsigned int currentRoom;	// Position of the room

		bool checkTile(dungeon::Room& room, ENTITIES& entities, unsigned int newXPos, unsigned int newYPos) const;
		char icon = 'E';			// Unicode representation of the entity
	protected:
		void createEntity(char pIcon, unsigned int xPos, unsigned yPos, unsigned int pRoom, EntityBehaviour pBehave);
		void createEntity(Entity& const e);
	public:
		unsigned int getX() const;
		unsigned int getY() const;
		int getVelocity() const;
		char getIcon() const;
		unsigned int getRoom() const; 
		EntityBehaviour getBehaviour() const; 

		unsigned int setX(int pX);
		unsigned int setY(int pY);
		int setVelocity(int pSpeed);
		char setIcon(char pIcon);
		unsigned int setRoom(unsigned int pRoom);
		EntityBehaviour setBehaviour(EntityBehaviour pBehave);

		bool atPos(unsigned int pX, unsigned int pY) const;

		void update(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);

		Entity() {
			this->createEntity('!', 0, 0, 0, ENTITY_STILL);
		}
		Entity(char pIcon, unsigned int pX, unsigned int pY, unsigned int pRoom, EntityBehaviour pBehave) {
			this->createEntity(pIcon, pX, pY, pRoom, pBehave);
		}

		static int entityAtPosition(ENTITIES& entities, unsigned int x, unsigned int y);

		bool canMoveRight(dungeon::Room& room, ENTITIES& entities) const;
		bool canMoveLeft(dungeon::Room& room, ENTITIES& entities) const;
		bool canMoveUp(dungeon::Room& room, ENTITIES& entities) const;
		bool canMoveDown(dungeon::Room& room, ENTITIES& entities) const;

		void moveRight(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveLeft(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveUp(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
		void moveDown(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities);
	};
}