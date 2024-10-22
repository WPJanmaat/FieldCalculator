#include "../../headers/Model/Particle.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/Control/ParticlePlacer.h"

ParticleList ListRelease(Particle* types, int* numP, int numTypes, Vector* position, Vector* velocities) {
    int totalParticles = 0;
    ParticleList Output;
    Output.length = 0;
    Output.List = NULL;
    for (int i=0; i<numTypes; i++) totalParticles+=numP[i];
    Particle* output = calloc(sizeof(Particle), totalParticles);
    int P = 0;
    if(totalParticles == 0) return Output;
    if(position == NULL) {
        fprintf(stderr, "Invalid input on ParticleList positions\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<numTypes; i++) {
        for(int j=0; j<numP[i]; j++) {
            //permits NULL for velocities input.
            output[P] = PutParticle(types[i], position[P], velocities == NULL ? zeroVector() : velocities[P]);
            P++;
        }
    } 
    Output.length = totalParticles;
    Output.List = output;
    return Output;
}

//grid release of particles (stationary)
ParticleList GridRelease(Particle* types, int* numP, int numTypes, double distance) {
    int totalParticles = 0;
    ParticleList Output;
    Output.length = 0;
    Output.List = NULL;
    
    for (int i=0; i<numTypes; i++) totalParticles+=numP[i];
    if(totalParticles == 0) return Output;
    Particle* output = calloc(sizeof(Particle), totalParticles);

    int placedParticles = 0;
    int placedSubParticles = 0;
    int atParticle=0;
    int i = 0; //layer height.
    //placed planally, top then sides then bottom over 4 different sections with different forms.
    while(placedParticles < totalParticles) {
        //top layer
        for(int j = -i; j <= i && placedParticles<totalParticles; j++) {
            for(int k = -i; k<= i && placedParticles<totalParticles; k++) {
                Vector position;
                position.x = j*distance;
                position.y = k*distance;
                position.z = i*distance;
                Vector velocity = zeroVector();
                output[placedParticles] = PutParticle(types[atParticle], position, velocity);
                placedParticles++;
                placedSubParticles++;
                if(placedSubParticles >= numP[atParticle]) {
                    placedSubParticles = 0;
                    atParticle++;
                }
            }
        }
        
        //left right layer here the top row must be skipped. (hence J becomes the z axis)
        for (int l = 0; l <=1; l++) {
            for (int j = -i; j<= i-1 && placedParticles < totalParticles; j++) {
                for (int k = -i; k<= i && placedParticles < totalParticles; k++) {
                    Vector position;
                    position.x = (i+(2*i*l))*distance; //+i at l=0, -i at l=1 for the opposite sides
                    position.y = k*distance;
                    position.z = j*distance;
                    Vector velocity = zeroVector();
                    output[placedParticles] = PutParticle(types[atParticle], position, velocity);
                    placedParticles++;
                    placedSubParticles++;
                    if(placedSubParticles >= numP[atParticle]) {
                        placedSubParticles = 0;
                        atParticle++;
                    }
                }
            }
        }

        //front back layer
        for (int l = 0; l <=1; l++) {
            for (int j = -i; j<= i-1 && placedParticles < totalParticles; j++) {
                for (int k = -i+1; k<= i-1 && placedParticles < totalParticles; k++) {
                    Vector position;
                    position.x = k*distance;
                    position.y = (i+(2*i*l))*distance; //+i at l=0, -i at l=1 for the opposite sides
                    position.z = j*distance;
                    Vector velocity = zeroVector();
                    output[placedParticles] = PutParticle(types[atParticle], position, velocity);
                    placedParticles++;
                    placedSubParticles++;
                    if(placedSubParticles >= numP[atParticle]) {
                        placedSubParticles = 0;
                        atParticle++;
                    }
                }
            }
        }

        //bottom layer
        for(int j = -i+1; j <= i-1 && placedParticles<totalParticles; j++) {
            for(int k = -i+1; k<= i-1 && placedParticles<totalParticles; k++) {
                Vector position;
                position.x = j*distance;
                position.y = k*distance;
                position.z = -i*distance;
                Vector velocity = zeroVector();
                output[placedParticles] = PutParticle(types[atParticle], position, velocity);
                placedParticles++;
                placedSubParticles++;
                if(placedSubParticles >= numP[atParticle]) {
                    placedSubParticles = 0;
                    atParticle++;
                }
            }
        }

        i++;
    }
    Output.length = totalParticles;
    Output.List = output;
    return Output;
}

/**publicly available function: Parses the release type and passes the parameters to the corresponding release function
 * Params: 
 * Particle* types: list of particles to be released,
 * int* numP: the number of particles for each type to be released,
 * int numTypes: the number of types of particles (length of types), 
 * double distance: interparticle distance (for grid),
 * Release type: type of particle release, 
 * Vector* position: For list release, gives position of each particle to be released, can be NULL for any non-list types,
 * Vector* velocities: similarly for list release, can be NULL even for list types, will default to 0 if null.
 * 
 * Return: Particle* array of particles released.
*/
ParticleList ParticleRelease(Particle* types, int* numP, int numTypes, double distance, Release type, Vector* position, Vector* velocities) {
    switch (type) {
        case grid:
            return GridRelease(types, numP, numTypes, distance);
            break;

        case list:
            return ListRelease(types, numP, numTypes, position, velocities);

        default:
            fprintf(stderr, "undefined or unimplememented release type\n");
            exit(EXIT_FAILURE);
            break;
    }
}