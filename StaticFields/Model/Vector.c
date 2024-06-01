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

Vector scalarDiv(Vector a, long double divisor) {
    Vector result;
    result.x = a.x/divisor;
    result.y = a.y/divisor;
    result.z = a.z/divisor;
    return result;
}

long double dotProduct(Vector a, Vector b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
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

Vector zeroVector() {
    Vector output;
    output.x = 0;
    output.y = 0;
    output.z = 0;
    return output;
}

void printVector(Vector a) {
    printf("x: %f.5, y: %f.5, z: %f.5\n", a.x, a.y, a.z);
}