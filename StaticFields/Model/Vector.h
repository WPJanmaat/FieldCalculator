//standard 3D vectors
typedef struct Vector {
    long double x;
    long double y;
    long double z;
} Vector;

Vector vecSum(Vector a, Vector b);
Vector scalarMult(Vector a, long double mult);