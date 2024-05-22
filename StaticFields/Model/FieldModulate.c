#include "Parameters.h"
#include "Vector.h"
#include "Field.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//returns the field strength at the given coordinates.
Vector ModulateField(Field ACField, Field DCField, Vector coordinates, int timestep, Parameters params) {
    Vector output;
    Vector ACForce = interpTriLin(ACField, coordinates);
    Vector DCForce = interpTriLin(DCField, coordinates);
    ACForce = scalarMult(ACForce, params.ACV*sin(timestep*params.freq*2*pi));
    DCForce = scalarMult(DCForce, params.DCV);
    output = vecSum(ACForce, DCForce);
    return output;
}

/*Trilinear interpolation
input: 
Field inputfield: the field from which values are teaken
Vector position: the position on which interpolation is done
*/
