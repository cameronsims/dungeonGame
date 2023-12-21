#include "Dungeon.hpp"

size_t dungeon::Dungeon::size() const {
	return this->height * this->width;
}
size_t dungeon::Dungeon::getWidth() const {
	return this->width;
}
size_t dungeon::Dungeon::getHeight() const {
	return this->height;
}

dungeon::Room* dungeon::Dungeon::getRooms() const {
	return this->rooms;
}

dungeon::Dungeon::Dungeon(Room* pRooms, size_t pWidth, size_t pHeight) : rooms(pRooms), width(pWidth), height(pHeight) {

}