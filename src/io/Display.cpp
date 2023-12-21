#include "Display.hpp"
#include "../entities/Entity.hpp"
#include "../rooms/Room.hpp"
#include "../rooms/DungeonMeta.hpp"


#include <stdio.h>
#include <vector>
#include <windows.h>

#include <stdio.h>

// ASSUME ENTITIES ARE LOADED!!!
void dungeon::printRoom(dungeon::Room* rooms, size_t roomSize, dungeon::Entity& player, ENTITIES& const entities) {
	//for (int i = 0; i < roomSize; i++) {											// For every single room
	const unsigned int currentRoom = player.getRoom();								// Get room of player
	dungeon::Room& room = rooms[currentRoom];										// Get current room
	for (int y = 0; y < room.getHeight(); y++) {									// Get every single vertical line
		const char* roomData = (char*)room.getRoom()[y].c_str();					// Get current row
		for (unsigned int x = 0; x < room.getLength(); x++) {						// For every single horizontal strip
			char icon = roomData[x];												// Current character
			int index = dungeon::Entity::entityAtPosition(entities, x, y);			// Index of entity at pos (negatite if none)
			if (index >= 0) {														// If there is an entity who exists at (i, y)
				icon = entities[index]->getIcon();									// Then print the entity reponsible
			}
			if (player.atPos(x, y)) {												// If player is here
				icon = player.getIcon();											// Get icon of player
			}
			printf("%c ", icon);													// Print character
		}
		printf("\n");																// Print new line
	}
}

void dungeon::printMap(Room* rooms, unsigned int currentRoom, size_t roomSize) {
	// For every single room
	for (unsigned int i = 0; i < roomSize; i++) {
		char inRoom = ' ';
		inRoom = (i == currentRoom) ? roomTypes[5] : roomTypes[rooms[i].getType()];
		printf(" %c%c", inRoom, (dungeon::Room::onEdge(i, roomSize)) ? '\n' : ' ');
	}
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