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
	Coord (const double newx, const double newy) : x(newx), y(newy) {}
	// Constructor
	Coord (const Coord& old_coord) : x(old_coord.x), y(old_coord.y) {}
	// Constructor
	
	//~~~~~~~~~~~~~~~~~~~~~~   Operator Overloading   ~~~~~~~~~~~~~~~~~~~~~~~~~//
	Coord operator+(const Coord& rhs);
	Coord operator+(const double& rhs);
	Coord operator+=(const Coord& rhs);
	Coord operator+=(const double& rhs);
	Coord operator-(const Coord& rhs);
	Coord operator-(const double& rhs);
	Coord operator-=(const Coord& rhs);
	Coord operator-=(const double& rhs);
	Coord operator*(const double& rhs);
	Coord operator*=(const double& rhs);
	Coord operator/(const double& rhs);
	Coord operator/=(const double& rhs);
	Coord operator=(const Coord& rhs);
	Coord operator=(const double& rhs);
	
	//~~~~~~~~~~~~~~~~~~~~~~~~~~   Data Members   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	double x, y;

};
