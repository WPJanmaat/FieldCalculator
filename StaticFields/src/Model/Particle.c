#include "../../headers/Model/Particle.h"
#include <stdio.h>
#include <stdlib.h>
#define e 1.60217663*pow(10, -19)

Vector getParPos(Particle p) {
    return p.position;
}

//Electric Coulomb force of a on b (= - b on a)
Vector getForce(Particle a, Particle b) {
    long double chargeForce = a.charge + b.charge * e;
    Vector output = scalarMult(vecMin(b.position, a.position), chargeForce);
    return output;
}

void printParticle(Particle a) {
    printf("Position: \n");
    printPosition(a);
    printf("Velocity: \n");
    printVelocity(a);

}

void printVelocity(Particle a) {
    printVector(a.velocity);
}

void printPosition(Particle a) {
    printVector(a.position);
}

//eliminates inative Particles and shortens the array accordingly. Returns new array length.
int eliminateParticles(Particle* ParticleList, int length) {
    for(int i = 0; i< length; i++) {
        if(!ParticleList[i].enabled) {
            printf("eliminating Particle %d, at position ", i);
            printPosition(ParticleList[i]);
            length--;
            for(int j = i; j<length; j++) {
                ParticleList[j] = ParticleList[j+1];
            }
            realloc(ParticleList, length);
        }
    }
    return length;
}

Particle createParticle(int charge, long double mass, long double impactParameter) {
    Particle ReturnParticle;
    ReturnParticle.enabled = 1;
    ReturnParticle.charge = charge;
    ReturnParticle.mass=mass;
    ReturnParticle.impactParameter = impactParameter;
}

Particle PutParticle(Particle type, Vector position, Vector velocity) {
    type.position = position;
    type.velocity = velocity;
    return type;
}

Particle* ConcatPraticle(Particle* list1, int len1, Particle* list2, int len2) {
    Particle* output = realloc(list1, len1+len2);
    for(int i=0; i<len2; i++) {
        output[i+len1] = list2[i];
    }
    return  output;
}

