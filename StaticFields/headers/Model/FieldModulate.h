#ifndef FIELDMODLUATE_H
#define FIELDMODULATE_H
#include "Field.h"
#include "Vector.h"
#include "Parameters.h"
/**
 * Finds the relevant Electromagnetic field values at a given coordinates.
 * @param Field ACField: the field subject to sinusoidal change
 * @param Field DCfield: the field that remains constant
 * @param Vecor coordinates: the given coordinates
 * @param int timestep: the timestep at which this evaluation takes place
 * @param Parameters params: the remaining (constant) simulation parameters.
*/
Vector ModulateField(Field* ACField, Field* DCField, Vector coordinates, int timestep, Parameters params);
#endif