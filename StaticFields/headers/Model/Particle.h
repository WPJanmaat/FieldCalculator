#ifndef PARTICLE_H
#define PARTICLE_H
#include "Vector.h"
//NOTE: the low numbers involved in this calculation may compromise accuracy due to Floating point arithmatic.
typedef struct Particle {
    char enabled; //Particles are disabled and not considered outside the relevant area, disabled Particles are cleared up every 100 steps.
    int charge; //in e
    double mass; //kg (sorry)
    Vector position;
    Vector velocity;
    Vector acceleration; // required for the leapfrog algorithm. Starts at 0.
    double impactParameter; //for use in the air calculations
} Particle;

//places particles of a given type at a given position with velocity.
Particle PutParticle(Particle type, Vector position, Vector velocity);

int eliminateParticles(Particle* ParticleList, int length, double time);

//charge in e (hence int), mass in Kg
Particle createParticle(int charge, double mass, double impactParameter);

void printPosition(Particle a);
Vector getParPos(Particle p);
Vector getForce(Particle a, Particle b, double scale);
Particle PutParticle(Particle type, Vector position, Vector velocity);
#endif