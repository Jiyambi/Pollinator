// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Text
//		The text class draws a string of text to the screen, and customizes the 
//		text's appearance and behavior.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Text.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Text::Text () : 
	font(NULL), 
	color(al_map_rgb(255,255,255)),
	align(ALLEGRO_ALIGN_CENTRE) {
}
Text::Text (ALLEGRO_FONT* new_font) :
	font(new_font), 
	color(al_map_rgb(255,255,255)), 
	align(ALLEGRO_ALIGN_CENTRE) {

}
Text::Text (ALLEGRO_FONT* new_font, int r, int g, int b) :
	font(new_font), 
	color(al_map_rgb(255,255,255)), 
	align(ALLEGRO_ALIGN_CENTRE) {
}
	
// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
void Text::draw() {

	if ( content.c_str() )
		al_draw_text(font, color, anchor.x, anchor.y, align, content.c_str());

}
	
// |----------------------------------------------------------------------------|
// |						  Operator Overloading								|
// |----------------------------------------------------------------------------|
Text Text::operator=(string rhs) {
	content = rhs;

	return *this;
}


// |----------------------------------------------------------------------------|
// |							   getSize()									|
// |----------------------------------------------------------------------------|
Coord Text::getSize() {
	Coord temp_coord;
	temp_coord.x = al_get_text_width(font, content.c_str());
	temp_coord.y = al_get_font_line_height(font);
	return temp_coord;
}