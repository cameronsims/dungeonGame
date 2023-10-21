#include "display.hpp"
#include "Room.hpp"
#include "Entity.hpp"

#include <stdio.h>
#include <vector>
#include <windows.h>

#include <stdio.h>

void dungeon::printRoom(dungeon::Room* rooms, size_t roomSize, dungeon::Entity& player, std::vector<dungeon::Entity>& entities) {
	//for (int i = 0; i < roomSize; i++) {									// For every single room
	int i = player.getRoom();												// Get room of player
	dungeon::Room& room = rooms[i];											// Get current room
	for (int y = 0; y < room.getHeight(); y++) {							// Get every single vertical line
		const char* roomData = (char*)rooms[i].getRoom()[y].c_str();		// Get current row
		for (int x = 0; x < room.getLength(); x++) {						// For every single horizontal strip
			char icon = roomData[x];										// Current character
			int index = dungeon::Entity::entityAtPosition(entities, x, y);	// Index of entity at pos (negatite if none)
			if (index >= 0 && i == entities[index].getRoom()) {				// If there is an entity who exists at (i, y) && the entity is in the room
				icon = entities[index].getIcon();							// Then print the entity reponsible
			}
			if (player.atPos(x, y)) {										// If player is here
				icon = player.getIcon();									// Get icon of player
			}
			printf("%c ", icon);											// Print character
		}
		printf("\n");														// Print new line
	}
	//}

	/*for (unsigned int i = 0; i < rooms[].getLength(); i++) {					// For every x value of the room
		for (unsigned int j = 0; j < room.getHeight(); j++) {				// For the y value of the room
			char icon = ' ';												// Icon/Character which we are going to print
			int index = dungeon::Entity::entityAtPosition(entities, j, i);	// Index of entity at pos (negative if none)
			if (index >= 0) {												// If there is an entity who exists at (i, j) && the entity is in the room
				icon = entities[index].getIcon();							// Then print the entity reponsible
			} else {														// Otherwise print a wall
				icon = room.getTile(i, j);									// Set the character to print to a room tile (null)
			}
			printf("%c ", icon);											// Print character
		}
		printf("\n");														// Print new line
	}*/
}

void dungeon::clearConsole() {
	constexpr COORD origin = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD data;

	GetConsoleScreenBufferInfo(console, &screen);							// Get data of window size

	const WORD colours= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;// Reset colours
	const DWORD size = screen.dwSize.X * screen.dwSize.Y;					// Get size of window by pixel^2

	FillConsoleOutputCharacterA(console, ' ', size, origin, &data);			// Fill console with empty spaces
	FillConsoleOutputAttribute(console, colours, size, origin, &data);		// Reset values in console
	SetConsoleCursorPosition(console, origin);								// Return Carrage
}

void dungeon::printMap(unsigned int currentRoom, size_t roomSize) {
	for (int i = 0; i < roomSize; i++) {		// For every single room
		if (i != currentRoom) {					// If we aren't in the room currently
			printf(" X ");						// Show X
		} else {								// Otherwise
			printf(" O ");						// Show O
		}
		if ((i + 1) % (int)sqrt(roomSize) == 0) {	// If we are on the edge
			printf("\n");						// Vertical line
		}
	}
}