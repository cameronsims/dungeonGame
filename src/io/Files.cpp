#include "Files.hpp"

#include <stdio.h>

// pCodeFile = the file the function was called from
// pFile = the file we want to access
// pFormat = the format we are using
// pContent = the payload we are putting in
void dungeon::fileWrite(const char* pCodeFile, const char* pFile, const char* pFormat, const char* pContent) {
	// Open file
	FILE* file;
	fopen_s(&file, pFile, "w");

	// Print everything
	fprintf(file, "%s: ", pCodeFile);
	fprintf(file, pFormat, pContent);

	// Close file
	fclose(file);
}