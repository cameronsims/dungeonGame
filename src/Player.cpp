#include "Player.hpp"

void dungeon::Player::moveRight(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->x == room.getLength() - 1) {
		this->x = 0;
		this->currentRoom++;
		return;
	}
	if (this->canMoveRight(room, entities)) {
		this->setX(this->getX() + this->getVelocity());
	}
}
void dungeon::Player::moveLeft(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->x == 0) {
		this->x = room.getLength() - 1;
		this->currentRoom--;
		return;
	}
	if (this->canMoveLeft(room, entities)) {
		this->setX(this->getX() - this->getVelocity());
	}
}
void dungeon::Player::moveUp(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->y == 0) {
		this->y = room.getHeight() - 1;
		this->currentRoom = this->currentRoom - sqrt(roomSize);
		return;
	}
	if (this->canMoveUp(room, entities)) {
		this->setY(this->getY() - this->getVelocity());
	}
}
void dungeon::Player::moveDown(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	dungeon::Room& room = rooms[this->currentRoom];
	if (this->y == room.getHeight() - 1) {
		this->y = 0;
		this->currentRoom = this->currentRoom + sqrt(roomSize);
		return;
	}
	if (this->canMoveDown(room, entities)) {
		this->setY(this->getY() + this->getVelocity());
	}
}