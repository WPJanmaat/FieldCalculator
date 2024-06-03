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

void freeFied(Field input);
#endif