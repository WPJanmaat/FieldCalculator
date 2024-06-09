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

//sums two vectors
Vector vecSum(Vector a, Vector b);

//scalar multiplication
Vector scalarMult(Vector a, long double mult);

//same as scalar multiplication, but with division instead (1/divisor) * a
Vector scalarDiv(Vector a, long double divisor);

//creates a vector of all 0s
Vector zeroVector();

//gets vector value of given dimension
long double getVecValue(Vector a, dimension dim);

//subtraction of vector a and b (a-b)
Vector vecMin(Vector a, Vector b);

//prints a vector.
void printVector(Vector a);
#endif