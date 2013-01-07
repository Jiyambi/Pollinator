// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Button
//		Defines a button's location, text, image, and function.

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Button.h"

// |----------------------------------------------------------------------------|
// |							   Constructor									|
// |----------------------------------------------------------------------------|
Button::Button() :
	text(0),
	click_sound(0),
	image_normal(0),
	image_selected(0),
	image_pressed(0),
	image_disabled(0),
	anchor(0,0),
	size(0,0),
	enabled(true),
	selected(false),
	pressed(false),
	mouse_down(false),
	error(0) {		

	debug ("Button: object instantiated.");
}

// |----------------------------------------------------------------------------|
// |							   Destructor									|
// |----------------------------------------------------------------------------|
Button::~Button() {
	delete text;	
	delete click_sound;	
	delete image_normal;		
	delete image_selected;		
	delete image_pressed;		
	delete image_disabled;		
	debug ("Button: object destroyed.");
}

// |----------------------------------------------------------------------------|
// |							     draw()										|
// |----------------------------------------------------------------------------|
// The draw function, which will be called by the screen or level.
int Button::draw() {
	debug ("Button: draw() called.", 10);

	// Draw the button's image
	if (enabled) {
		if (pressed) {
			if (image_pressed) image_pressed->draw();
			else if (image_selected) image_selected->draw();
			else if (image_normal) image_normal->draw();
		}
		else if (selected) {
			if (image_selected) image_selected->draw();
			else if (image_normal) image_normal->draw();
		}
		else {
			if (image_normal) image_normal->draw();
		}
	}
	else {
		if (image_disabled) image_disabled->draw();
		else if (image_normal) image_normal->draw();
	}

	if(text) text->draw();

	return error;
}


// |----------------------------------------------------------------------------|
// |							    logic()										|
// |----------------------------------------------------------------------------|
int Button::logic(int mouse_x, int mouse_y) {
	debug ("Button: logic() called.", 10);

	// Detects mouse movement into the button. If the mouse button is down,
	//		sets button to pressed as well as selected.
	if (mouse_x >= anchor.x && mouse_x <= anchor.x+size.x 
		&& mouse_y >= anchor.y && mouse_y <= anchor.y+size.y && !selected) {
		debug ("Button: mouse-in detected");
		selected = true;
		if(mouse_down) pressed = true;
	}

	// Detects mouse movement out of the button. Also unpresses button.
	else if ((mouse_x < anchor.x || mouse_x > anchor.x+size.x 
		|| mouse_y < anchor.y || mouse_y > anchor.y+size.y ) && selected) {
		debug ("Button: mouse-out detected");
		selected = false;
		pressed = false;
	}

	return error;
}

// |----------------------------------------------------------------------------|
// |							    onMouseDown()								|
// |----------------------------------------------------------------------------|
int Button::onMouseDown(int button) {
	debug ("Button: onMouseDown() called.");

	if (selected) pressed = true;
	mouse_down = true;

	return error;
}

// |----------------------------------------------------------------------------|
// |							     onMouseUp()								|
// |----------------------------------------------------------------------------|
int Button::onMouseUp(int button) {
	debug ("Button: onMouseUp() called.");

	if (enabled && selected && pressed) {
		pressed = false;
		if(click_sound) click_sound->play();
		onClick();
	}
	mouse_down = false;

	return error;
}

// |----------------------------------------------------------------------------|
// |							     onKeyDown()								|
// |----------------------------------------------------------------------------|
int Button::onKeyDown(int button) {
	debug ("Button: onKeyDown() called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							      onKeyUp() 		 						|
// |----------------------------------------------------------------------------|
int Button::onKeyUp(int button) {
	debug ("Button: onKeyUp() called.");

	return error;
}

// |----------------------------------------------------------------------------|
// |							      setAnchor() 		 						|
// |----------------------------------------------------------------------------|
void Button::setAnchor(Coord new_anchor) {
	debug ("Button: setAnchor() called.");

	anchor = new_anchor;
	if(text) text->setAnchor(new_anchor+size/2);
	if(image_normal) image_normal->setAnchor(new_anchor);	
	if(image_selected) image_selected->setAnchor(new_anchor);	
	if(image_pressed) image_pressed->setAnchor(new_anchor);	
	if(image_disabled) image_disabled->setAnchor(new_anchor);

}