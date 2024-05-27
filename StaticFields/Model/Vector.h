#ifndef VECTOR_H
#define VECTOR_H

//standard 3D vectors
typedef struct Vector {
    long double x;
    long double y;
    long double z;
} Vector;

typedef enum dimensions {
    x,
    y,
    z
} dimension;

Vector vecSum(Vector a, Vector b);
Vector scalarMult(Vector a, long double mult);
Vector ScalarDiv(Vector a, long double divisor);
Vector zeroVector();
long double getVecValue(Vector a, dimension dim);
Vector vecMin(Vector a, Vector b);
#endif