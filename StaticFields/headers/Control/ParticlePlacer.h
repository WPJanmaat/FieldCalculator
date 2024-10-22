#ifndef PARTICLEPLACER_H
#define PARTICLEPLACER_H
#include "../Model/Vector.h"
#include "../Model/Particle.h"


//different release types, can be expended as implemented. e.g. diffusion, stimulated release etc.
typedef enum Release {
    grid,
    list
} Release;

/** 
 * @param Particle* types: list of particles to be released,
 * @param int* numP: the number of particles for each type to be released,
 * @param int numTypes: the number of types of particles (length of types), 
 * @param double distance: interparticle distance (for grid),
 * @param Release type: type of particle release, 
 * @param Vector* position: For list release, gives position of each particle to be released, can be NULL for any non-list types,
 * @param Vector* velocities: similarly for list release, can be NULL even for list types, will default to 0 if null.
 * 
 * @return: Particle* array of particles released.
*/
ParticleList ParticleRelease(Particle* types, int* numP, int numTypes, double distance, Release type, Vector* position, Vector* velocities);

#endif