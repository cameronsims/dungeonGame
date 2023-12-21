#pragma once

#define DUNGEON_CLEAR '.'
#define DUNGEON_WALL '#'
#define DUNGEON_DOOR_HORIZONTAL '-'
#define DUNGEON_DOOR_VERTICAL '|'

#define DUNGEON_ROOM_MAX_HEIGHT 6
#define DUNGEON_ROOM_MIN_HEIGHT 5
#define DUNGEON_ROOM_MAX_LENGTH 6
#define DUNGEON_ROOM_MIN_LENGTH 5

#define DUNGEON_ROOM_EMPTY_CHANCE 40

#define DUNGEON_ENEMY_MAX 32
#define DUNGEON_ROOM_ENEMY_MAX_BASE 2

namespace dungeon {
	// Types of rooms
	constexpr char roomTypes[6] = {
		// USER NOT IN
		'O',	// NORMAL ROOM
		'^',	// Begin
		'v',	// End
		' ',	// Empty Room
		'!',	// Special Room
		// User in
		'X'		// Room the user is currently in 
	};

	const enum consoleColours {
		COLOUR_BLACK = 0, COLOUR_BLUE, COLOUR_GREEN, 
		COLOUR_CYAN, COLOUR_RED, COLOUR_MAGENTA, 
		COLOUR_BROWN, COLOUR_LIGHTGRAY, COLOUR_DARKGRAY, 
		COLOUR_LIGHTBLUE, COLOUR_LIGHTGREEN, COLOUR_LIGHTCYAN, 
		COLOUR_LIGHTRED, COLOUR_LIGHTMEGENTA, COLOUR_YELLOW, COLOUR_WHITE
	};

	const enum dungeonType {
		DUNGEON_NORMAL = 0,
		DUNGEON_BEGIN,
		DUNGEON_END,
		DUNGEON_EMPTY,
		DUNGEON_SPECIAL
	};

	constexpr size_t dungeonAmounts = 5;
	const enum dungeonColour {
		DUNGEON_DEFAULT = 0,
		DUNGEON_COLD,
		DUNGEON_HOT,
		DUNGEON_NATURAL,
		DUNGEON_CAVE
	};

	// Text, Background
	constexpr consoleColours dungeonColourMap[dungeonAmounts][2] = {
		{ COLOUR_WHITE, COLOUR_BLACK },			// Default Mode
		{ COLOUR_CYAN, COLOUR_BLUE },			// Cold Mode
		{ COLOUR_YELLOW, COLOUR_RED},			// Hot Mode
		{ COLOUR_BROWN, COLOUR_GREEN },			// Natural
		{ COLOUR_LIGHTGRAY, COLOUR_DARKGRAY }	// Cave
	};

	enum class Movement {
		MOVE_STILL = 0,
		MOVE_UP,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT
	};
}