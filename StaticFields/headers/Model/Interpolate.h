#include "Vector.h"
#include "Field.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef INTERPOLATE_H
#define INTERPOLATE_H
Vector interpolateVec(Vector a, Vector b, long double fraction);
Vector interpTriLin(Field inputField, Vector position);
#endif