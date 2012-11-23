// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Image
//		Contains a graphic and it's coordinates and dimensions. It can draw the 
//		image to a screen.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Coord.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: Image							|
// |----------------------------------------------------------------------------|
class Image {

public:

	Image ();
	// Default constructor

	Image (ALLEGRO_BITMAP* new_graphic);
	// Constructor

	void virtual draw();
	// Draws the image to the active bitmap;

	void virtual setAnchor(Coord new_anchor) { anchor = new_anchor; }
	// Set a new anchor for the image.
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ALLEGRO_BITMAP* graphic;		// Pointer to graphic (NOT managed by the image, instead managed by graphics manager)
    Coord anchor;					// Location on the screen (of upper left corner)
    Coord size;						// Width and height of the image
    int alpha;						// Transparency of the image. Normally set to 100, if set to a different number, uses a different draw method.
    int angle; // in radians		// Orientation, used for rotating images, 0 if the image should not be rotated.

};