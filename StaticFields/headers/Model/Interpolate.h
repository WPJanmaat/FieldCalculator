#ifndef INTERPOLATE_H
#define INTERPOLATE_H

#include "Vector.h"
#include "Field.h"
#include <stdio.h>
#include <stdlib.h>
//Helper function interpolating two vectors, fraction gives the distance between the vectors with 0 being at vector a and 1 at vector b
/**interpolate a vector along a given axis
 * Parameters:
 * Vector a: the first (lower) vector
 * Vector b: the second (higher) vector
 * double fraction: the fraction of the distance between a and b where the interpolation point resides
*/
Vector interpolateVec(Vector a, Vector b, double fraction);

/**
 * Interpolates (Triliniarly) a field around a given vector position
 * @param Field* inputField: The field in which the interpolation takes place; 
 * @param Vector position: the position around which the interpolation is done
 * 
 * @return The interpolated vector
*/
Vector interpTriLin(Field* inputField, Vector position);
#endif