#include "UserInterface.hpp"
#include "OperatingSystem.hpp"

CONSOLE_TYPE dungeon::Console::console = OS_GETHANDLE(OS_THISCONSOLE);

void dungeon::Console::setColour(unsigned char pHex) {
	OS_CONSOLE_CHANGE_COLOUR(dungeon::Console::console, pHex);
}

void dungeon::Console::sleep(time_t ms) {
	OS_SLEEP(ms);
}