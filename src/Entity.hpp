#pragma once

#include <vector>

#include "Room.hpp"

namespace dungeon {
	class Entity {
	protected:
		unsigned int x;				// Horizontal Location (From the left)
		unsigned int y;				// Vertical Location (From the top)
		int baseSpeed = 1;			// Speed by default
		int speed = 1;				// Speed is mutliplied by 1 (base speed).

		unsigned int currentRoom;	// Position of the room

		bool checkTile(dungeon::Room& room, std::vector<dungeon::Entity>& entities, unsigned int newXPos, unsigned int newYPos) const;
		char icon = 'E';			// Unicode representation of the entity
	public:
		unsigned int getX() const;
		unsigned int getY() const;
		int getVelocity() const;
		char getIcon() const;
		unsigned int getRoom() const; 

		unsigned int setX(int pX);
		unsigned int setY(int pY);
		int setVelocity(int pSpeed);
		char setIcon(char pIcon);
		unsigned int setRoom(unsigned int pRoom);

		bool atPos(unsigned int pX, unsigned int pY) const;

		Entity()																 : icon('!'),   x(0),  y(0),  currentRoom(0) {}
		Entity(char pIcon, unsigned int pX, unsigned int pY, unsigned int pRoom) : icon(pIcon), x(pX), y(pY), currentRoom(pRoom) {}

		static int entityAtPosition(std::vector<Entity> entities, unsigned int x, unsigned int y);

		bool canMoveRight(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const;
		bool canMoveLeft(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const;
		bool canMoveUp(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const;
		bool canMoveDown(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const;

		void moveRight(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
		void moveLeft(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
		void moveUp(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
		void moveDown(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities);
	};
}