#include "Entity.hpp"

bool dungeon::Entity::checkTile(dungeon::Room& room, std::vector<dungeon::Entity>& entities, unsigned int newXPos, unsigned int newYPos) const {
	int index = Entity::entityAtPosition(entities, newXPos, newYPos);	// The index of the entity at the position (negative if none)
	if (index > 0) {													// If there is at least one individual
		return entities[index].getRoom() != entities[0].getRoom();		// And if there is an entity, then the entity must be in the same room
	}
	return room.getTile(newXPos, newYPos) != DUNGEON_WALL;						// Return false is there is a wall
}

unsigned int dungeon::Entity::getX() const {
	return this->x;
}

unsigned int dungeon::Entity::getY() const {
	return this->y;
}

int dungeon::Entity::getVelocity() const {
	return this->speed;
}

unsigned int dungeon::Entity::getRoom() const {
	return this->currentRoom;
}

char dungeon::Entity::getIcon() const {
	return this->icon;
}

unsigned int dungeon::Entity::setX(int pX) {
	this->x = pX;
	return this->x;
}

unsigned int dungeon::Entity::setY(int pY) {
	this->y = pY;
	return this->y;
}

int dungeon::Entity::setVelocity(int pSpeed) {
	this->speed = pSpeed;
	return this->speed;
}
unsigned int dungeon::Entity::setRoom(unsigned int pRoom) {
	this->currentRoom = pRoom;
	return this->currentRoom;
}

char dungeon::Entity::setIcon(char pIcon) {
	this->icon = pIcon;
	return this->icon;
}

bool dungeon::Entity::atPos(unsigned int pX, unsigned int pY) const {
	// Return if the entity is at the same x and y values
	return ((this->x == pX) && (this->y == pY));
}

int dungeon::Entity::entityAtPosition(std::vector<Entity> entities, unsigned int x, unsigned int y) {
	for (int i = 0; i < entities.size(); i++) {	// For every entity in our array 
		if (entities[i].atPos(x, y)) {			// If the entity is in positon
			return i;							// Return index found at
		}
	}
	return -1;									// Else there is none, return negative value
}

bool dungeon::Entity::canMoveRight(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const {
	const unsigned int xPos = this->getX();
	const unsigned int yPos = this->getY();
	const unsigned int projectedX = xPos + this->getVelocity();
	// If there is an entity or wall
	return this->checkTile(room, entities, projectedX, yPos);
}

bool dungeon::Entity::canMoveLeft(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const {
	const unsigned int xPos = this->getX();
	const unsigned int yPos = this->getY();
	const unsigned int projectedX = xPos - this->getVelocity();
	// If there is an entity or wall
	return this->checkTile(room, entities, projectedX, yPos);
}

bool dungeon::Entity::canMoveUp(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const {
	const unsigned int xPos = this->getX();
	const unsigned int yPos = this->getY();
	const unsigned int projectedY = yPos - this->getVelocity();
	// If there is an entity or wall
	return this->checkTile(room, entities, xPos, projectedY);
}

bool dungeon::Entity::canMoveDown(dungeon::Room& room, std::vector<dungeon::Entity>& entities) const {
	const unsigned int xPos = this->getX();
	const unsigned int yPos = this->getY();
	const unsigned int projectedY = yPos + this->getVelocity();
	// If there is an entity or wall
	return this->checkTile(room, entities, xPos, projectedY);
}

void dungeon::Entity::moveRight(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	if (this->canMoveRight(rooms[this->getRoom()], entities)) {
		this->setX(this->getX() + this->getVelocity());
	}
}
void dungeon::Entity::moveLeft(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	if (this->canMoveLeft(rooms[this->getRoom()], entities)) {
		this->setX(this->getX() - this->getVelocity());
	}
}
void dungeon::Entity::moveUp(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	if (this->canMoveUp(rooms[this->getRoom()], entities)) {
		this->setY(this->getY() - this->getVelocity());
	}
}
void dungeon::Entity::moveDown(dungeon::Room* rooms, size_t roomSize, std::vector<dungeon::Entity>& entities) {
	if (this->canMoveDown(rooms[this->getRoom()], entities)) {
		this->setY(this->getY() + this->getVelocity());
	}
}