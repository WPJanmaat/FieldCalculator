#include "field.h"

#ifndef FIELD_H
#define FIELD_H
long double *fieldGetX(Field input, int index){
    if(index < 0 || index >= input.lengthX){
        return NULL;
    }
    return (input.Xvals+index);
}

long double *fieldGetY(Field input, int index){
    if(index < 0 || index >= input.lengthY){
        return NULL;
    }
    return (input.Yvals+index);
}

long double *fieldGetZ(Field input, int index){
    if(index < 0 || index >= input.lengthZ){
        return NULL;
    }
    return (input.Zvals+index);
}


#endif