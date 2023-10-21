
#include "Room.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Display.hpp"
#include "Movement.hpp"

#include <conio.h>
#include <windows.h>

int main() {
	// Make an input
	dungeon::Keyboard input;
	// Generate map
	constexpr size_t roomSize = 9;
	dungeon::Room rooms[roomSize] = { 
		dungeon::Room(7,7, 0, roomSize),
		dungeon::Room(7,7, 1, roomSize),
		dungeon::Room(7,7, 2, roomSize),
		dungeon::Room(7,7, 3, roomSize),
		dungeon::Room(7,7, 4, roomSize),
		dungeon::Room(7,7, 5, roomSize),
		dungeon::Room(7,7, 6, roomSize),
		dungeon::Room(7,7, 7, roomSize),
		dungeon::Room(7,7, 8, roomSize)
	};

	HANDLE consoleColour = GetStdHandle(STD_OUTPUT_HANDLE);				// Get Ability to change Windows console colour

	std::vector<dungeon::Entity> entities;
	entities.push_back( dungeon::Player(2, 2, 0) );
	entities.push_back( dungeon::Entity('E', 1, 1, 4) );
	entities.push_back( dungeon::Entity('E', 5, 3, 4) );

	dungeon::Player& player = (dungeon::Player&)entities[0];

	unsigned int txtColour = 0;
	unsigned int bgColour = 0;

	while (true) {
		// Current room that the player is in
		dungeon::Room& currentRm = rooms[player.getRoom()];
		// Set Console Attributes
		txtColour = dungeon::COLOUR_CYAN;												// Hex Value 1: 0X X=[0->15]
		bgColour = dungeon::COLOUR_BLUE;												// Hex Value 2: X0 X=[0->15]
		SetConsoleTextAttribute(consoleColour, txtColour + (bgColour * 16));			// Colour code of console

		dungeon::printRoom(rooms, roomSize, player, entities);

		SetConsoleTextAttribute(consoleColour, dungeon::COLOUR_WHITE + (dungeon::COLOUR_BLACK));		// Colour code of console

		printf("Player: %u, %u\n", player.getX(), player.getY());
		printf("Room  : %u\n", player.getRoom());

		dungeon::printMap(player.getRoom(), roomSize);
		
		// Get input from user
		dungeon::Movement move = dungeon::Movement::MOVE_STILL; 
		// While we are not moving, wait for a keyboard input 
		while (move == dungeon::Movement::MOVE_STILL) {
			move = input.getMovementInput();
			// Depending on input, execute one of the following
			switch (move) {
				case dungeon::Movement::MOVE_UP:    { player.moveUp(rooms, roomSize, entities); break; }
				case dungeon::Movement::MOVE_LEFT:  { player.moveLeft(rooms, roomSize, entities); break; }
				case dungeon::Movement::MOVE_DOWN:  { player.moveDown(rooms, roomSize, entities); break; }
				case dungeon::Movement::MOVE_RIGHT: { player.moveRight(rooms, roomSize, entities); break; }
			}
			Sleep(30);
		}
		dungeon::clearConsole();
	}
}