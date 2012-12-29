// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Main
//		Initiallization and setup for the game.

// TODO
//	- Figure out why keyboard isn't working
//	- Add buttons
//	- Add music
//	- Add zen mode screen
//	- Add zen mode background
//	- Add bee
//	- Add bee controls
//	- Add flowers
//	- Add pollen
//	- Add scoring UI
//	- Add pesticide

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

	Game game;
	if(game.init()){
		debug("Main: failed to initialise the game object.");
		return -1;
	}

	return game.run();

}