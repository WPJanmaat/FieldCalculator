#include "../../headers/Model/Particle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 1.60217663E-19
#define e0 8.55E-12

Vector getParPos(Particle p) {
    return p.position;
}

//Electric Coulomb force of a on b (= - b on a)
Vector getForce(Particle a, Particle b, double scale) {
    double chargeForce = a.charge * b.charge;
    double factor = 1/(4*pi*e0);
    double distance = getDistance(a.position, b.position);
    //a makeunit function exists, but since the length of this vector was already known this avoids redundancy
    Vector direction = scalarDiv(vecMin(b.position, a.position), distance);
    return scalarMult(direction, factor*chargeForce/(distance*scale*distance*scale));
}

void printVelocity(Particle a) {
    printVector(a.velocity);
}

void printPosition(Particle a) {
    printVector(a.position);
}

void printParticle(Particle a) {
    printf("Position: \n");
    printPosition(a);
    printf("Velocity: \n");
    printVelocity(a);

}

//eliminates inative Particles and shortens the array accordingly. Returns new array length.
int eliminateParticles(ParticleList* ParticleList, double time) {
    for(int i = 0; i< (*ParticleList).length; i++) {
        if(!(*ParticleList).List[i].enabled) {
            printf("eliminating Particle %d, time %lf, at position ", i, time);
            printPosition((*ParticleList).List[i]);
            ParticleList->length--;
            for(int j = i; j<(*ParticleList).length-1; j++) {
                ParticleList[j] = ParticleList[j+1];
            }
            ParticleList = realloc(ParticleList, ParticleList->length);
        }
    }
    return ParticleList->length;
}

Particle createParticle(double charge, double mass, double impactParameter) {
    Particle ReturnParticle;
    ReturnParticle.enabled = 1;
    ReturnParticle.charge = charge * e;
    ReturnParticle.mass=mass;
    ReturnParticle.impactParameter = impactParameter;
    return ReturnParticle;
}

Particle PutParticle(Particle type, Vector position, Vector velocity) {
    type.position = position;
    type.velocity = velocity;
    type.acceleration = zeroVector();
    return type;
}

Particle* ConcatPraticle(Particle* list1, int len1, Particle* list2, int len2) {
    Particle* output = realloc(list1, len1+len2);
    for(int i=0; i<len2; i++) {
        output[i+len1] = list2[i];
    }
    return  output;
}

