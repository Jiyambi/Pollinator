// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Text
//		The text class draws a string of text to the screen, and customizes the 
//		text's appearance and behavior.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"
#include "Coord.h"
#include <string>
using namespace std;

// |----------------------------------------------------------------------------|
// |						  Class Definition: Text							|
// |----------------------------------------------------------------------------|
class Text {

public:
	
	// Constructors
	Text ();
	Text (ALLEGRO_FONT* new_font);
	Text (ALLEGRO_FONT* new_font, int r, int g, int b);
	
	// Draws the image to the active bitmap;
	void virtual draw();

	// Getters
	int virtual getAlign() { return align; }
	Coord virtual getSize();

	// Setters
	void virtual setAlign(int flag) { align = flag; }
	void virtual setAnchor(Coord new_anchor) { anchor = new_anchor; }

	// Operator Overloading
	Text operator=(string rhs);
	
protected:

	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	ALLEGRO_FONT* font;				// Pointer to graphic (NOT managed by the image, instead managed by graphics manager)
    Coord anchor;					// Location on the screen (of upper left corner)
	ALLEGRO_COLOR color;			// Represents the foreground (text) color.
	int align;						// Aligned center, left, or right.
	string content;	 				// The content of the text.

};