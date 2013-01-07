// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Player
//		Controls the player object's position, movement, image, and actions. 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"
#include "Circle.h"
#include "Assets.h"
#include "Screen.h"

// |----------------------------------------------------------------------------|
// |					      Class Definition: Player							|
// |----------------------------------------------------------------------------|
class Player : public Circle {
	
public:

	Player (Assets& assets);
	// Constructor

	~Player ();
	// De-constructor

	int virtual logic(int mouse_x, int mouse_y);
	// Performs logic functions for the object
	
	// Input functions
	int virtual onMouseDown(int button);
	int virtual onMouseUp(int button);
	
protected:
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Coord target;
	Coord mouse_position;
	bool has_target;
	double speed;
};
