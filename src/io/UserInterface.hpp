#pragma once

#include "OperatingSystem.hpp"

namespace dungeon {
	class Console {
	private:
		static CONSOLE_TYPE console;
	public:
		static void setColour(unsigned char pHex);
		static void sleep(time_t ms);
	};
}