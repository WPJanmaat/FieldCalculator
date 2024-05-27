#include "Particle.h"
#include <stdio.h>
#include <stdlib.h>

Vector getParPos(particle p) {
    return p.position;
}

Vector getForce(particle a, particle b) {
    Vector output;
    return output;
}

//eliminates inative particles and shortens the array accordingly. Returns new array length.
int eliminateParticles(particle* particleList, int length) {
    for(int i = 0; i< length; i++) {
        if(!particleList->enabled) {
            length--;
            for(int j = i; j<length; j++) {
                particleList[j] = particleList[j+1];
            }
            realloc(particleList, length);
        }
    }
    return length;
}