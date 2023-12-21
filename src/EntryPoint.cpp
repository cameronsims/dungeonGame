// Rooms
#include "rooms/Dungeon.hpp"
#include "rooms/Room.hpp"
#include "rooms/DungeonMeta.hpp"
#include "rooms/RoomGenerator.hpp"
#include "rooms/EntityGenerator.hpp"
#include "rooms/RoomWorm.hpp"
// Entities
#include "entities/Entity.hpp"
#include "entities/Enemy.hpp"
#include "entities/Player.hpp"
// In / Out
#include "io/Display.hpp"
#include "io/Movement.hpp"
#include "io/UserInterface.hpp"

int main() {
	// The amount of rooms Horizontally / Vertically
	constexpr unsigned int dungeonWidth = 8, dungeonHeight = 8;

	dungeon::Keyboard input;													// Input from the user
	HANDLE consoleColour = GetStdHandle(STD_OUTPUT_HANDLE);						// Get Ability to change Windows console colour

	dungeon::Room* rooms = new dungeon::Room[dungeonWidth * dungeonHeight];		// The rooms of the dungeon
	dungeon::Dungeon chamber(rooms, dungeonWidth, dungeonHeight);				// The Dungeon and the meta

	// All entities
	std::vector<dungeon::Entity> entities;	// Entities 
	ENTITIES loadedEntities;				// Loaded Entities
	std::vector<dungeon::Enemy*> enemies;	// Enemies (NOT PLAYER!!)

	// Reserve spot for player
	entities.push_back(dungeon::Player(3, 3, chamber.getHeight() * 4 + chamber.getWidth() / 2));

	// CONTENTS CHANGE THE VECTOR KEEP THIS BELOW!!!
	dungeon::Player& const player = (dungeon::Player&)entities[0];

	dungeon::Worm worm(player.getRoom(), &chamber);			// Generate path for the rooms
	worm.start();											// Generate a path, stored in the worm
	dungeon::generateRooms(rooms, chamber, worm.getPath());	// Generate the Rooms
	dungeon::generateEnemies(&chamber, entities, player);	// Generate the Enemies
	dungeon::setEnemies(enemies, entities);					// Put the enemies in the entity list into the enemy vector

	// If this is false, then it will end the program
	bool playing = true;
	// Game Counter
	unsigned long long counter = 0;
	// Game loop
	while (playing) {
		// Current room that the player is in
		dungeon::Room* currentRm = &rooms[player.getRoom()];

		// Show the room with the dimensions
		printf("Room %d: (%dx%d)\n", player.getRoom(), currentRm->getLength(), currentRm->getHeight());

		// Set the console to the colour of the room
		dungeon::Console::setColour(currentRm->getRoomHex());			// Colour code of console=

		// Print the room
		dungeon::printRoom(rooms, chamber.size(), player, loadedEntities);

		// Set back to the default console colour
		dungeon::Console::setColour(dungeon::COLOUR_WHITE + (dungeon::COLOUR_BLACK));		// Colour code of console

		// Print the map 
		dungeon::printMap(rooms, player.getRoom(), chamber.size());

		// Get input from user
		dungeon::Movement move = dungeon::Movement::MOVE_STILL; 

		// While we are not moving, wait for a keyboard input 
		while (move == dungeon::Movement::MOVE_STILL || counter == 20) {
			// Increase counter to refresh
			counter++;

			// Get an input from thr user
			move = input.getMovementInput();
			player.update(rooms, chamber.size(), loadedEntities);

			// Depending on input, move the player
			player.move(rooms, chamber.size(), loadedEntities, move);

			// Check if we've moved rooms
			if (currentRm != &rooms[player.getRoom()]) {
				loadedEntities.clear();
				// For all enemies
				for (dungeon::Enemy* e : enemies) {
					// If they are in the same room
					if (e->getRoom() == player.getRoom()) {
						// Add them to the vector
						loadedEntities.push_back(e);
					}
				}
			}

			// Update all entities every 10 ticks
			if (counter == 20) {
				// Reset the counter
				counter = 0;

				// Get updates for all loaded entities
				for (dungeon::Entity* ent : loadedEntities) {
					dungeon::Enemy* enemy = (dungeon::Enemy*)ent;
					enemy->update(rooms, chamber.size(), &player, loadedEntities);
				}
				break;
			}
			// Wait for 30 ms
			dungeon::Console::sleep(30);
		}
		// Clear the entire console
		dungeon::clearConsole();
	}

	delete[] rooms;

	return 0;
}