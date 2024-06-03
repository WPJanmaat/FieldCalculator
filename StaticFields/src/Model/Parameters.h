/*parameters define the (more or less) static parameters of the general trap.
NB: the dimensionality of the trap is decided by the input fields (generated from e.g. COMSOL)*/
#define pi 3.14159265359

typedef struct Parameters {
    long double DCV;
    long double ACV;
    long double freq;
    long double pressure;
    long double dt;

    long double startTime;
    long double endTime;

    //boundary condition for the sim, exceeding this will disable (and ultimately remove) the violating particle.
    //Upper = higher, lower = ...lower (i.e. higherX>lowerX)
    long double upperX;
    long double lowerX;
    long double upperY;
    long double lowerY;
    long double upperZ;
    long double lowerZ;
} Parameters;