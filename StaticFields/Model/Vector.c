#include "Vector.h"
#include "Field.h"
#include <stdio.h>
#include <stdlib.h>
Vector vecSum(Vector a, Vector b){
    Vector result;
    result.x = a.x+b.x;
    result.y = a.y+b.y;
    result.z = a.z+b.z;
    return result;
}

//a - b
Vector vecMin(Vector a, Vector b) {
    Vector result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
}

Vector scalarMult(Vector a, long double mult) {
    Vector result;
    result.x = a.x*mult;
    result.y = a.y*mult;
    result.z = a.z*mult;
}

long double getVecValue(Vector a, dimension dim) {
    switch(dim) {
        case x:
            return a.x;
            break;
        case y:
            return a.y;
            break;
        case z:
            return a.z;
            break;
    }
    //This should *never* be reached.
    fprintf(stderr, "something went horribly wrong in getVecValue");
    EXIT_FAILURE;
    return 0;
}
