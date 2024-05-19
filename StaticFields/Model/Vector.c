#include "vector.h"

Vector vecSum(Vector a, Vector b){
    Vector result;
    result.x = a.x+b.x;
    result.y = a.y+b.y;
    result.z = a.z+b.z;
    return result;
}

Vector scalarMult(Vector a, long double mult) {
    Vector result;
    result.x = a.x*mult;
    result.y = a.y*mult;
    result.z = a.z*mult;
}