#include "Parameters.h"
#include "Vector.h"
#include "Field.h"
#include <math.h>

//returns the field strength at the given coordinates.
Vector ModulateField(Field ACField, Field DCField, Vector coordinates, int timestep, Parameters params) {
    Vector output;
    Vector ACForce = interpTriLin(ACField, coordinates, params);
    Vector DCForce = interpTriLin(DCField, coordinates, params);
    ACForce = scalarMult(ACForce, params.ACV*sin(timestep*params.freq*2*pi));
    DCForce = scalarMult(DCForce, params.DCV);
    output = vecSum(ACForce, DCForce);
    return output;
}

Vector interpTrilin(Field inputField, Vector position, Parameters params) {
    Vector output;


    return output;
}