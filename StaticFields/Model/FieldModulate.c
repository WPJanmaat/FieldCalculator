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
Vector interpTriLin(Field inputField, Vector position) {
    Vector output;
    //x
    long double *lowerX = fieldGetX(inputField, (int)floor(position.x/inputField.steplengthX));
    if(lowerX == NULL) {
        fprintf(stderr, "Interpolation out of lower bound in x, particle outside of field?");
        EXIT_FAILURE;
    }
    long double *upperX = fieldGetX(inputField, (int)ceil(position.x/inputField.steplengthX));
    if(upperX == NULL) {
        fprintf(stderr, "Interpolation out of upper bound in x, particle outside of field?");
        EXIT_FAILURE;
    }
    long double LowV = *lowerX;
    long double HighV = *upperX;
    output.x = LowV+ (HighV*LowV)*((position.x-LowV)/(HighV-LowV));


    //y
    long double *lowerY = fieldGetY(inputField, (int)floor(position.y/inputField.steplengthY));
    if(lowerX == NULL) {
        fprintf(stderr, "Interpolation out of lower bound in y, particle outside of field?");
        EXIT_FAILURE;
    }
    long double *upperY = fieldGetY(inputField, (int)ceil(position.y/inputField.steplengthY));
    if(upperX == NULL) {
        fprintf(stderr, "Interpolation out of upper bound in y, particle outside of field?");
        EXIT_FAILURE;
    }
    LowV = *lowerY;
    HighV = *upperY;
    output.y = LowV+ (HighV*LowV)*((position.y-LowV)/(HighV-LowV));


    //z
    long double *lowerZ = fieldGetZ(inputField, (int)floor(position.z/inputField.steplengthZ));
    if(lowerX == NULL) {
        fprintf(stderr, "Interpolation out of lower bound in z, particle outside of field?");
        EXIT_FAILURE;
    }
    long double *upperZ = fieldGetZ(inputField, (int)ceil(position.z/inputField.steplengthZ));
    if(upperX == NULL) {
        fprintf(stderr, "Interpolation out of upper bound in z, particle outside of field?");
        EXIT_FAILURE;
    }
    LowV = *lowerZ;
    HighV = *upperZ;
    output.z = LowV+ (HighV*LowV)*((position.y-LowV)/(HighV-LowV));

    return output;
}