#ifndef PARTICLE_H
#define PARTICLE_H
#include "Vector.h"
//NOTE: the low numbers involved in this calculation may compromise accuracy due to Floating point arithmatic.
typedef struct particle {
    char enabled; //particles are disabled and not considered outside the relevant area, disabled particles are cleared up every 100 steps.
    int charge; //in e
    long double mass;
    Vector position;
    Vector veloity;
    long double impactParameter; //for use in the air calculations
} particle;
#endif