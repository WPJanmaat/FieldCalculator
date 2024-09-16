#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Model/Field.h"

Vector *fieldGet(Field* input, int indexX, int indexY, int indexZ) {
    if(indexX < 0 || indexX >= (*input).lengthX){
        return NULL;
    }
    if(indexY < 0 || indexY >= (*input).lengthY){
        return NULL;
    }
    if(indexZ < 0 || indexZ >= (*input).lengthZ){
        return NULL;
    }
    if(indexX == 0 | indexX == ((*input).lengthX-1)) fprintf(stderr, "WARNING: field value collected at field edge X");
    if(indexY == 0 | indexY == ((*input).lengthY-1)) fprintf(stderr, "WARNING: field value collected at field edge Y");
    if(indexZ == 0 | indexZ == ((*input).lengthZ-1)) fprintf(stderr, "WARNING: field value collected at field edge Z");
    return ((*input).FieldValues[indexX][indexY]+indexZ);
}

//ordinary 3D array free for the held values.
void freeField(Field* input) {
    for (int i = 0; i<(*input).lengthX; i++) {
        for (int j = 0; j<(*input).lengthY; j++) {
            free(input->FieldValues[i][j]);
        }
        free(input->FieldValues[i]);
    }
    (*input).lengthX = 0;
    (*input).lengthY = 0;
    (*input).lengthZ = 0;
    free(input->FieldValues);
}

//gets field vector at a given position (rounded down), X, Y and Z offset included
Vector *fieldGetPos(Field* input, Vector position, int offsetX, int offsetY, int offsetZ) {
    //initialisation to prevent object.value in the calculations
    double Xstart = (*input).startX;
    double Ystart = (*input).startY;
    double Zstart = (*input).startZ;
    double xpos, ypos, zpos;
    double stepX, stepY, stepZ;
    xpos = getVecValue(position, x);
    ypos = getVecValue(position, y);
    zpos = getVecValue(position, z);
    stepX = (*input).steplengthX;
    stepY = (*input).steplengthY;
    stepZ = (*input).steplengthZ;

    //calculations
    int indexX = (int)((xpos - Xstart)/stepX);
    int indexY = (int)((ypos - Ystart)/stepY);
    int indexZ = (int)((zpos - Zstart)/stepZ);

    return fieldGet(input, indexX+offsetX, indexY+offsetY, indexZ+offsetZ);
}
