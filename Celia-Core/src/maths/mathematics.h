#pragma once

//use defines that are not part of standard cmath
#define _USE_MATH_DEFINES 
#include <cmath>

#include "vect2.h"
#include "vect3.h"
#include "vect4.h"
#include "matrix4.h"

namespace celia {namespace maths {

#ifndef M_PI
namespace
{
	const double M_PI = std::acos(-1.0);
}
#endif

inline float to_radians(float degrees)
{
	return degrees * ((float)M_PI / 180.0f);
}

} }