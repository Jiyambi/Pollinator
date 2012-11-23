// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Image
//		Contains a graphic and it's coordinates and dimensions. It can draw the 
//		image to a screen.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Image.h"


// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Image::Image() : 
	graphic(NULL),
	alpha(0),
	angle(0) {}

Image::Image(ALLEGRO_BITMAP* new_graphic) : 
	graphic(new_graphic),
	alpha(0),
	angle(0) {

	// Get size
	size.x = al_get_bitmap_width(graphic);
	size.y = al_get_bitmap_height(graphic);
}
	
// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
void Image::draw() {
	if (graphic) {
		if (angle) {
			if (alpha) {
				al_draw_tinted_rotated_bitmap(graphic, 
					al_map_rgba_f(1, 1, 1, alpha), size.x/2, size.y/2, 
					anchor.x + size.x/2, anchor.y + size.y/2, angle, 0);
			}
			else {
				al_draw_rotated_bitmap(graphic, size.x/2, size.y/2, 
					anchor.x + size.x/2, anchor.y + size.y/2, angle, 0);
			}
		}
		else {
			al_draw_bitmap(graphic, anchor.x, anchor.y, 0);
		}
	}
}