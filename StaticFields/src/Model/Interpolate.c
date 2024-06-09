#include "../../headers/Model/Interpolate.h"
/**interpolate a vector along a given axis
 * Parameters:
 * Vector a: the first (lower) vector
 * Vector b: the second (higher) vector
 * long double fraction: the fraction of the distance between a and b where the interpolation point resides
*/
Vector interpolateVec(Vector a, Vector b, long double fraction) {
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

    //i and j determine the offset, 0 is the lower bound value 1 is the higher bound value for x and y respectively.
    Vector InterpTwice[2];
    for(int i = 0; i <= 1; i++) {
        //partials will contain vectors interpolated across the z axis at the given i and j values
        Vector partials[2];
        for (int j = 0; j <= 1; j ++ ) {
            Vector *holder = fieldGetPos(inputField, position, i, j, 0);
            if (holder == NULL) {
                fprintf(stderr, "Null input on Fieldget in interpolation (out of bounds?)\n");
                EXIT_FAILURE;    
            }
            Vector lowerVec = *holder;

            holder = fieldGetPos(inputField, position, i, j ,1);
            if (holder == NULL) {
                fprintf(stderr, "Null input on Fieldget in interpolation (out of bounds?)\n");
                EXIT_FAILURE;                
            }
            Vector higherVec = *holder;
            partials[j] = interpolateVec(lowerVec, higherVec, fracZ);
        }
        InterpTwice[i] = interpolateVec(partials[0], partials[1], fracY);
    }
    return interpolateVec(InterpTwice[0], InterpTwice[1], fracX);
}
