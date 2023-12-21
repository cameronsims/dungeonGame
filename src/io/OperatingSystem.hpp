#pragma once

#define PROGRAM_WINDOWS true
//#define PROGRAM_LINUX false

////////////////////////////////////////////////////////////////////////
// Windows Operating System ////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

#ifdef PROGRAM_WINDOWS

#include <windows.h>

#define CONSOLE_TYPE HANDLE

#define OS_GETHANDLE(handle) GetStdHandle(handle)

#define OS_THISCONSOLE STD_OUTPUT_HANDLE
#define OS_CONSOLE_CHANGE_COLOUR(console, hex) SetConsoleTextAttribute(console, hex)

#define OS_SLEEP(ms) Sleep(ms)

#endif

////////////////////////////////////////////////////////////////////////
// Linux Operating System //////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

#ifdef PROGRAM_LINUX

#define CONSOLE_TYPE // TYPE THAT HOLDS THE CONSOLE / WINDOW WE ARE IN

#define OS_GETHANDLE(handle) // TYPE THAT GETS THE ACTUAL WINDOW / INPUT / OUTPUT

#define OS_THISCONSOLE // The console output
#define OS_CONSOLE_CHANGE_COLOUR(console, hex) // The function to change colours

#define OS_SLEEP(ms) // Hold thread for a few seconds

#endif PROGRAM_LINUX