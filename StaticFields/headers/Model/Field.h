#ifndef FIELD_H
#define FIELD_H
#include "Vector.h"
//A simple 3D Field construction
typedef struct Field {
    //number of entries
    int lengthX;
    int lengthY;
    int lengthZ;

    long double steplengthX;
    long double startX;
    long double steplengthY;
    long double startY;    
    long double steplengthZ;
    long double startZ;
    Vector ***FieldValues;
} Field;

/**
 * Frees an input field, does not delete the struct, but frees the internal 3D array.
 * @param Field Input: the field to be freed.
*/
void freeField(Field* input);

/**
 * Gets the field values at a given index in the 3D array
 * @param Field* input: the field from which the vector is retrieved.
 * @param int indexX: the x index of the array.
 * @param int indexY: the y index of the array.
 * @param int indexZ: the z index of the array.
 * 
 * @return FieldValues[x][y][z];
*/
Vector *fieldGet(Field* input, int indexX, int indexY, int indexZ);

/**
 * Gets the field values at a given position, selects closest x, y and z values rounded *down*
 * @param Field* input: the field from which the vector is retrieved.
 * @param Vector position: the position for which the field value must be retrieved.
 * @param int offsetX: the x offset in the array.
 * @param int offsetY: the y offset in the array.
 * @param int offsetZ: the z offset in the array.
 * 
 * @return x,y,z are rounded to down the nearest values that have field values (xf,yf,zf respectively), then FieldValues[xf+offsetX][yf+offsetY][zf+offsetZ] is returned;
*/
Vector *fieldGetPos(Field* input, Vector position, int offsetX, int offsetY, int offsetZ);
#endif