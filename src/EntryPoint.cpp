// Rooms
#include "rooms/Room.hpp"
#include "rooms/DungeonMeta.hpp"
#include "rooms/RoomGenerator.hpp"
#include "rooms/RoomWorm.hpp"
// Entities
#include "entities/Entity.hpp"
#include "entities/Enemy.hpp"
#include "entities/Player.hpp"
// In / Out
#include "io/Display.hpp"
#include "io/Movement.hpp"

#include <conio.h>
#include <windows.h>

int main() {
	// Make an input
	dungeon::Keyboard input;
	// Console Handler
	HANDLE consoleColour = GetStdHandle(STD_OUTPUT_HANDLE);				// Get Ability to change Windows console colour
	// Generate map
	constexpr size_t roomSize = 8*8;
	// The vector of the dungeon
	dungeon::dungeonColour clr = dungeon::DUNGEON_DEFAULT;
	// Create room array
	dungeon::Room rooms[roomSize];
	// All entities
	std::vector<dungeon::Entity> entities;
	entities.push_back( dungeon::Player(5, 5, 4) );
	entities.push_back( dungeon::Enemy('E', 2, 2, 4, dungeon::ENEMY_VERTICAL) );
	entities.push_back( dungeon::Enemy('E', 5, 3, 4, dungeon::ENEMY_HORIZONTAL) );
	// Entity that is the player
	dungeon::Player& const player = (dungeon::Player&)entities[0];
	std::vector<dungeon::Enemy*> enemies;
	// If they are an enemy, then make sure they are in the reference vector
	for (int i = 0; i < entities.size(); i++) {
		if (entities[i].getBehaviour() != dungeon::ENTITY_PLAYER) {
			enemies.push_back((dungeon::Enemy*)&entities[i]);
		}
	}
	// Loaded Enemies
	ENTITIES loadedEntities;
	std::vector<dungeon::Enemy*> loadedEnemies;
	// Prepare to load the room
	dungeon::Worm worm(player.getRoom(), sqrt(roomSize), sqrt(roomSize));
	worm.start();
	dungeon::generateRooms(rooms, roomSize, worm.getPath());
	// If this is false, then it will end the program
	bool playing = true;
	// Game Counter
	unsigned long long counter = 0;
	// Game loop
	while (playing) {
		// Current room that the player is in
		dungeon::Room& currentRm = rooms[player.getRoom()];
		
		printf("Room %d: (%dx%d)\n", player.getRoom(), currentRm.getLength(), currentRm.getHeight());

		// Set the console to the colour of the room
		SetConsoleTextAttribute(consoleColour, currentRm.getRoomHex());			// Colour code of console
		// Print the room
		dungeon::printRoom(rooms, roomSize, player, loadedEntities);
		// Set back to the default console colour
		SetConsoleTextAttribute(consoleColour, dungeon::COLOUR_WHITE + (dungeon::COLOUR_BLACK));		// Colour code of console
		// Print the map 
		dungeon::printMap(rooms, player.getRoom(), roomSize);
		// Reset Counter
		int i = 0;
		// Reset loaded entities if we are in a different room
		if (loadedEnemies.size() > 0) {
			if (player.getRoom() != loadedEnemies[0]->getRoom()) {
				loadedEnemies.clear();
			}
		}
		// Get input from user
		dungeon::Movement move = dungeon::Movement::MOVE_STILL; 
		// While we are not moving, wait for a keyboard input 
		while (move == dungeon::Movement::MOVE_STILL || counter == 20) {
			// Increase counter to refresh
			counter++;
			// Get an input from thr user
			move = input.getMovementInput();
			player.update(rooms, roomSize, loadedEntities);
			// Depending on input, execute one of the following
			switch (move) {
				case dungeon::Movement::MOVE_UP:    { player.moveUp   (rooms, roomSize, loadedEntities); break; }
				case dungeon::Movement::MOVE_LEFT:  { player.moveLeft (rooms, roomSize, loadedEntities); break; }
				case dungeon::Movement::MOVE_DOWN:  { player.moveDown (rooms, roomSize, loadedEntities); break; }
				case dungeon::Movement::MOVE_RIGHT: { player.moveRight(rooms, roomSize, loadedEntities); break; }
			}
			// Update all entities every 10 ticks
			if (counter % 20 == 0) {
				// Reset the counter
				counter = 0;
				// For all entities
				for (unsigned int i = 0; i < loadedEnemies.size(); i++) {
					// If the entity is not a player or still
					if (loadedEnemies[i]->getBehaviour() != dungeon::ENTITY_PLAYER && loadedEnemies[i]->getBehaviour() != dungeon::ENTITY_STILL) {
						// Then update it
						loadedEnemies[i]->update(rooms, roomSize, loadedEntities);
					}
				}
				break;
			}
			// Wait for 30 ms
			Sleep(30);
		}
		// Clear the entire console
		dungeon::clearConsole();
	}
}