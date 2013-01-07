// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Circle
//		Governs movement, collision detection, and drawing for a 
//      circle object. 
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Util.h"
#include "Assets.h"
#include "Coord.h"
#include "Image.h"


// |----------------------------------------------------------------------------|
// |						  Class Definition: Circle							|
// |----------------------------------------------------------------------------|
class Circle {

public:

	Circle ();
	// Constructor

	~Circle();
	// Destructor

	int virtual draw();
	// Draws the object to the active bitmap

	int virtual logic(int mouse_x, int mouse_y);
	// Performs logic functions for the object
	
	// Input functions
	int virtual onMouseDown(int button);
	int virtual onMouseUp(int button);
	int virtual onKeyDown(int button);
	int virtual onKeyUp(int button);

	// Setter functions
	void virtual setPosition(Coord new_position);
	void virtual setAngle(double new_angle);
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	Coord position;		// Position of the center of the circle
	Coord velocity;		// Velocity of the circle (updates the position in the logic function)
	double radius;		// Radius of the circle
	double angle;		// Angle of rotation (to be passed to image)

	Image* graphic;		// Graphic for the circle

	int error;			// Error code

};