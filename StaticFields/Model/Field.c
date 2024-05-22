#include <stdio.h>
#include <stdlib.h>
#include "field.h"

Vector *fieldGet(Field input, int indexX, int indexY, int indexZ){
    if(indexX < 0 || indexX >= input.lengthX){
        return NULL;
    }
    if(indexY < 0 || indexY >= input.lengthY){
        return NULL;
    }
    if(indexZ < 0 || indexZ >= input.lengthZ){
        return NULL;
    }
    return (input.FieldValues[indexX][indexY]+indexZ);
}

//Helper function which interpolates along a given axis to avoid redundant code.
Vector GetInterpolate(Field inputField, Vector position, dimension axis) {
    
}

//TODO: separate to interpolator.c file
Vector interpTriLin(Field inputField, Vector position) {
    //0 is lower, 1 is higher
    long double Xvals[2], Yvals[2], Zvals[2];
    //position.x/inputField.steplengthX
    Xvals[0] = floor(getVecValue(position, x));
    Xvals[1] = ceil(getVecValue(position, x));
    Yvals[0] = floor(getVecValue(position, y));
    Yvals[1] = ceil(getVecValue(position, y));
    Zvals[0] = floor(getVecValue(position, z));
    Zvals[1] = ceil(getVecValue(position, z));

    //only used to extract the positional fraction.
    long double fracX, fracY, fracZ;
    fracX = (getVecValue(position, x)-Xvals[0])/(Xvals[1]-Xvals[0]);
    fracY = (getVecValue(position, y)-Yvals[0])/(Yvals[1]-Yvals[0]);
    fracZ = (getVecValue(position, z)-Zvals[0])/(Zvals[1]-Zvals[0]);

    //0 for lower position, 1 for higher position.
    int Xpos[2], Ypos[2], Zpos[2];
    for(int i = 0; i< 1; i++){
        Xpos[i] = (int)((getVecValue(position, x)/inputField.steplengthX)+i);
        Ypos[i] = (int)((getVecValue(position, y)/inputField.steplengthY)+i);
        Zpos[i] = (int)((getVecValue(position, z)/inputField.steplengthZ)+i);
    }

    Vector InterpTwice[2];
    for(int i = 0; i < 1; i++) {
        //partials will contain vectors interpolated across the z axis at the given i and j values
        Vector partials[2];
        for (int j = 0; j < 1; j ++ ) {
            Vector *holder = fieldGet(inputField, Xpos[i], Ypos[j], Zpos[0]);
            if (holder == NULL) {
                fprintf(stderr, "Null input on Fieldget in interpolation") {
                    EXIT_FAILURE;
                }
            }
            Vector lowerVec = *holder;

            holder = fieldGet(inputField, Xpos[i], Ypos[j], Zpos[1]);
            if (holder == NULL) {
                fprintf(stderr, "Null input on Fieldget in interpolation") {
                    EXIT_FAILURE;
                }
            }
            Vector higherVec = *holder;
            partials[j] = interpolateVec(lowerVec, higherVec, fracZ);
        }
        InterpTwice[i] = interpolateVec(partials[0], partials[1], fracY);
    }
    return interpolateVec(InterpTwice[0], InterpTwice[1], fracX);
}
