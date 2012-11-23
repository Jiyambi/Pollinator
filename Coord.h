// Pollinator - C++ Desktop Version
// Developed by Bounder Studios
// Copyright Sarah Herzog, 2011, all rights reserved.
//
// Coord
//		Coord is a coordinate set (x and y) which measures the position of 
//		something on the screen. The data members for this class will be 
//		public.
#pragma once

// |----------------------------------------------------------------------------|
// |								Includes									|
// |----------------------------------------------------------------------------|
#include "Constants.h"

// |----------------------------------------------------------------------------|
// |						  Class Definition: Coord							|
// |----------------------------------------------------------------------------|
class Coord {

public:

	Coord () : x(0), y(0) {}
	// Default constructor
	
	//~~~~~~~~~~~~~~~~~~~~~~   Operator Overloading   ~~~~~~~~~~~~~~~~~~~~~~~~~//
	Coord operator+(Coord& rhs);
	Coord operator+(int& rhs);
	Coord operator+(float& rhs);
	Coord operator+=(Coord& rhs);
	Coord operator+=(int& rhs);
	Coord operator+=(float& rhs);
	Coord operator-(Coord& rhs);
	Coord operator-(int& rhs);
	Coord operator-(float& rhs);
	Coord operator-=(Coord& rhs);
	Coord operator-=(int& rhs);
	Coord operator-=(float& rhs);
	Coord operator*(int& rhs);
	Coord operator*(float& rhs);
	Coord operator*=(int& rhs);
	Coord operator*=(float& rhs);
	Coord operator/(int& rhs);
	Coord operator/(float& rhs);
	Coord operator/=(int& rhs);
	Coord operator/=(float& rhs);
	Coord operator=(Coord& rhs);
	Coord operator=(int& rhs);
	Coord operator=(float& rhs);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	int x, y;

};
