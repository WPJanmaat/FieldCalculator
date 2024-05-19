/*parameters define the (more or less) static parameters of the general trap.
NB: the dimensionality of the trap is decided by the input fields (generated from e.g. COMSOL)*/
#define pi 3.14159265359

typedef struct Parameters {
    long double DCV;
    long double ACV;
    long double freq;
    long double pressure;
} Parameters;