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
void freeField(Field input);
Vector *fieldGet(Field* input, int indexX, int indexY, int indexZ);
#endif