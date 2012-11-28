// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Main
//		Initiallization and setup for the game.

// TODO
//	- Add mouse support to Input
//	- Add keyboard support to Input
//	- Add callback functions to Input for handling mouse and keyboard
//	- Move timing functions to Input
//	- Remove all Allegro references from Game
//	- Ensure all Allegro code is confined to main, Input, Assets (and it's managers), and wrapper classes (Image, Text, etc)
//	- Add click to change screen functionality to TitleScreen - loads MenuScreen.
//	- Ensure that OnLoad, onExit, isDone, etc all work properly.
//	- Add text
//	- Add buttons
//	- Begin gameplay work (additional todos to be fleshed out later)

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