#include "../../headers/Model/Interpolate.h"
#include <math.h>
Vector interpolateVec(Vector a, Vector b, double fraction) {
    Vector result;
    Vector component;
    component = vecMin(b, a);
    component = scalarMult(component, fraction);
    result = vecSum(a, component);
    return result;
}


/*Trilinear interpolation
input: 
Field inputfield: the field from which values are teaken
Vector position: the position on which interpolation is done
*/
Vector interpTriLin(Field* inputField, Vector position) {
    //0 is lower, 1 is higher
    double Xvals[2], Yvals[2], Zvals[2];
    //position.x/inputField.steplengthX
    double Xpos = getVecValue(position, x);
    int steps = (Xpos-inputField->startX)/inputField->steplengthX;
    Xvals[1] = inputField->startX + steps*(inputField->steplengthX);
    while(Xvals[1]<= Xpos) {
        Xvals[1]+=inputField->steplengthX;
    }        
    Xvals[0] = Xvals[1]-inputField->steplengthX;
        
    double Ypos = getVecValue(position, y);
    steps = (Ypos-inputField->startY)/inputField->steplengthY;
    Yvals[1] = inputField->startY + steps*(inputField->steplengthY);

    while(Yvals[1]<= Ypos) {
        Yvals[1]+=inputField->steplengthY;
    }
    Yvals[0] = Yvals[1]-inputField->steplengthY;

    double Zpos = getVecValue(position, z);
    steps = (Zpos-inputField->startZ)/inputField->steplengthZ;
    Zvals[1] = inputField->startZ + steps*(inputField->steplengthZ);

    while(Zvals[1]<= Zpos) {
        Zvals[1] += inputField ->steplengthZ;
    }
    Zvals[0] = Zvals[1]-inputField->steplengthZ;

    //only used to extract the positional fraction.
    double fracX, fracY, fracZ;
    fracX = (Xpos-Xvals[0])/(Xvals[1]-Xvals[0]); //Identical to inputField->steplengthX, used to insulate Field Variables
    fracY = (Ypos-Yvals[0])/(Yvals[1]-Yvals[0]);
    fracZ = (Zpos-Zvals[0])/(Zvals[1]-Zvals[0]);

    //i and j determine the offset, 0 is the lower bound value 1 is the higher bound value for x and y respectively.
    Vector InterpTwice[2];
    for(int i = 0; i <= 1; i++) {
        //partials will contain vectors interpolated across the z axis at the given i and j values
        Vector partials[2];
        for (int j = 0; j <= 1; j ++ ) {
            Vector *holder = fieldGetPos(inputField, position, i, j, 0);
            if (holder == NULL) {
                fprintf(stderr, "Null input on Fieldget in interpolation (out of bounds?)\n");
                exit(EXIT_FAILURE);    
            }
            Vector lowerVec = *holder;

            holder = fieldGetPos(inputField, position, i, j ,1);
            if (holder == NULL) {
                fprintf(stderr, "Null input on Fieldget in interpolation (out of bounds?)\n");
                exit(EXIT_FAILURE);                
            }
            Vector higherVec = *holder;
            partials[j] = interpolateVec(lowerVec, higherVec, fracZ);
        }
        InterpTwice[i] = interpolateVec(partials[0], partials[1], fracY);
    }
    return interpolateVec(InterpTwice[0], InterpTwice[1], fracX);
}
