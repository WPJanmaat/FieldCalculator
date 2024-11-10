/*parameters define the (more or less) static parameters of the general trap.
NB: the dimensionality of the trap is decided by the input fields (generated from e.g. COMSOL)*/
#ifndef PARAMETERS_H
#define PARAMETERS_H

#define pi 3.14159265359

typedef struct Parameters {
    double DCV;
    double ACV;
    double freq;
    double pressure;
    double dt;

    double startTime;
    double endTime;

    double scale;
    double timescale;

    //boundary condition for the sim, exceeding this will disable (and ultimately remove) the violating particle.
    //Upper = higher, lower = ...lower (i.e. higherX>lowerX)
    double upperX;
    double lowerX;
    double upperY;
    double lowerY;
    double upperZ;
    double lowerZ;
} Parameters;

#endif