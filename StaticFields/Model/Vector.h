//standard 3D vectors
typedef struct Vector {
    long double x;
    long double y;
    long double z;
} Vector;

Vector vecSum(Vector a, Vector b);
Vector scalarMult(Vector a, long double mult);

typedef enum dimensions {
    x,
    y,
    z
} dimension;

long double getVecValue(Vector a, dimension dim);
Vector interpolateVec(Vector a, Vector b, long double fraction);