#pragma once

namespace dungeon {
	const enum consoleColours {
		COLOUR_BLACK = 0, COLOUR_BLUE, COLOUR_GREEN, 
		COLOUR_CYAN, COLOUR_RED, COLOUR_MAGENTA, 
		COLOUR_BROWN, COLOUR_LIGHTGRAY, COLOUR_DARKGRAY, 
		COLOUR_LIGHTBLUE, COLOUR_LIGHTGREEN, COLOUR_LIGHTCYAN, 
		COLOUR_LIGHTRED, COLOUR_LIGHTMEGENTA, COLOUR_YELLOW, COLOUR_WHITE
	};

	constexpr size_t dungeonAmounts = 5;
	const enum dungeonColour {
		DUNGEON_DEFAULT,
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