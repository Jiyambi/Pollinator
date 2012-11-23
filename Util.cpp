// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Util
//		Game-wide utilities.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Util.h"

void debug(const char* msg, int level) 
{ 
	if (level <= DEBUG_MODE)
	{
		OutputDebugString(msg);
		OutputDebugString("\n");
	}
}