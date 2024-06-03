#ifndef FIELDMODLUATE_H
#define FIELDMODULATE_H
#include "Field.h"
#include "Vector.h"
#include "Parameters.h"
Vector ModulateField(Field ACField, Field DCField, Vector coordinates, int timestep, Parameters params);
#endif