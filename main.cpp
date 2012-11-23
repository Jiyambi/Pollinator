// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Main
//		Initiallization and setup for the game.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"
#include "Game.h"

// |----------------------------------------------------------------------------|
// |								  Main										|
// |----------------------------------------------------------------------------|
int main(int argc, char **argv)
{
	// Initiallize Allegro and Install Mouse
	if(!al_init()) {
		debug("Main: failed to initialise allegro.");
		return -1;
	}
	debug("Main: Allegro initialised.");
	if(!al_install_mouse()) {
		debug("Main: failed to initialise the mouse.");
		return -1;
	}
	debug("Main: mouse initialised.");
	Game game;
	return game.run();

}