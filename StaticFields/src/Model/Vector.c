#include "../../headers/Model/Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

Vector scalarMult(Vector a, double mult) {
    Vector result;
    result.x = a.x*mult;
    result.y = a.y*mult;
    result.z = a.z*mult;
}

Vector scalarDiv(Vector a, double divisor) {
    Vector result;
    result.x = a.x/divisor;
    result.y = a.y/divisor;
    result.z = a.z/divisor;
    return result;
}

double dotProduct(Vector a, Vector b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

double getVecValue(Vector a, dimension dim) {
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
    fprintf(stderr, "something went horribly wrong in getVecValue\n");
    exit(EXIT_FAILURE);
    return 0;
}

Vector zeroVector() {
    Vector output;
    output.x = 0;
    output.y = 0;
    output.z = 0;
    return output;
}

Vector invertVec(Vector a) {
    a.x = -a.x;
    a.y = -a.y;
    a.z = -a.z;
    return a;
}

//gets the distance between vector a and b
double getDistance(Vector a, Vector b) {
    return getlength(vecMin(a,b));
}

Vector makeUnit(Vector a) {
    double length = getlength(a);
    return scalarDiv(a, length);
}

double getlength(Vector a) {
    return sqrt(dotProduct(a, a));
}

void printVector(Vector a) {
    printf("x: %lf, y: %lf, z: %lf\n", a.x, a.y, a.z);
}