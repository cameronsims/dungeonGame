#include "Player.hpp"

void dungeon::Player::setMiddleVertical(Room& room) {
	this->x = (this->x != 0) ? 0 : room.getLength() - 1;
	this->y = room.getHeight() / 2;
}
void dungeon::Player::setMiddleHorizontal(Room& room) {
	this->x = room.getLength() / 2;
	this->y = (this->y != 0) ? 0 : room.getHeight() - 1;
}

void dungeon::Player::enterNewRoom(Room& room, ENTITIES& entities, size_t roomSize, size_t newRoom) {
	// If we moved horizontally
	if (this->currentRoom == newRoom - 1 || this->currentRoom == newRoom + 1) {
		this->setMiddleVertical(room);
	}
	// If we moved vertically
	else if (Room::roomAbove(this->currentRoom, roomSize) == newRoom || Room::roomBelow(this->currentRoom, roomSize) == newRoom) {
		this->setMiddleHorizontal(room);
	}
	// Set the new room
	this->currentRoom = newRoom;
	entities.clear();
}

void dungeon::Player::moveRight(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->x == room.getLength() - 1) {
		this->enterNewRoom(rooms[currentRoom + 1], entities, roomSize, currentRoom + 1);
		return;
	}
	if (this->canMoveRight(room, entities)) {
		this->setX(this->getX() + this->getVelocity());
	}
}
void dungeon::Player::moveLeft(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->x == 0) {
		this->enterNewRoom(rooms[currentRoom - 1], entities, roomSize, currentRoom - 1);
		return;
	}
	if (this->canMoveLeft(room, entities)) {
		this->setX(this->getX() - this->getVelocity());
	}
}
void dungeon::Player::moveUp(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->y == 0) {
		this->enterNewRoom(rooms[this->currentRoom - (int)sqrt(roomSize)], entities, roomSize, this->currentRoom - sqrt(roomSize));
		return;
	}
	if (this->canMoveUp(room, entities)) {
		this->setY(this->getY() - this->getVelocity());
	}
}
void dungeon::Player::moveDown(dungeon::Room* rooms, size_t roomSize, ENTITIES& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->y == room.getHeight() - 1) {
		this->enterNewRoom(rooms[this->currentRoom + (int)sqrt(roomSize)], entities, roomSize, this->currentRoom + sqrt(roomSize));
		return;
	}
	if (this->canMoveDown(room, entities)) {
		this->setY(this->getY() + this->getVelocity());
	}
}