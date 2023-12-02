#pragma once

#define DUNGEON_CLEAR '.'
#define DUNGEON_WALL '#'
#define DUNGEON_DOOR_HORIZONTAL '-'
#define DUNGEON_DOOR_VERTICAL '|'

#define DUNGEON_ROOM_MAX_HEIGHT 6
#define DUNGEON_ROOM_MIN_HEIGHT 5
#define DUNGEON_ROOM_MAX_LENGTH 6
#define DUNGEON_ROOM_MIN_LENGTH 5

namespace dungeon {
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
}