#ifndef PARTICLE_H
#define PARTICLE_H
#include "Vector.h"
#include "Particle.h"
//NOTE: the low numbers involved in this calculation may compromise accuracy due to Floating point arithmatic.
typedef struct particle {
    char enabled; //particles are disabled and not considered outside the relevant area, disabled particles are cleared up every 100 steps.
    int charge; //in e
    long double mass;
    Vector position;
    Vector veloity;
    Vector acceleration; // required for the leapfrog algorithm. Starts at 0.
    long double impactParameter; //for use in the air calculations
} particle;
#endif

Vector getParPos(particle p);
Vector getForce(particle a, particle b);
