#include "Particle.h"
#include "FieldModulate.h"
#include "Field.h"

void Simulate(particle* particleList, Field ACField, Field DCField, int length, Parameters params) {
    int i=0;
    int j=0;
    while(i*params.dt+params.startTime < params.endTime) {
        for(int i = 0; i*params.dt+params.startTime < params.endTime && i < 100*j; i++){
            simulateStep(particleList, ACField, DCField, length, i, params);
        }
        length = eliminateParticles(particleList, length);
        j++;
    }
}

void simulateStep(particle *particleList, Field ACField, Field DCField, int length, int timestep, Parameters params){
    Vector *forceList = calloc(sizeof(Vector), length);
    for (int i=0; i++; i<length) {
        Vector NextForce = ModulateField(ACField, DCField, getParPos(particleList[i]), timestep, params);
        for (int j=i+1; j++; j<length) {
            Vector Pforce = getForce(particleList[i], particleList[j]);
            forceList[i] = vecSum(forceList[i], Pforce);
            forceList[j] = vecSum(forceList[j], scalarMult(Pforce, -1));
        }
        NextForce = vecSum(NextForce, forceList[i]);
    }
}

particle updateParticle(particle input, Vector Force, Parameters params) {
    if(input.enabled) {
        //leapfrog implementation
        Vector CurrentPos = input.position;
        Vector CurrentAcc = input.acceleration;
        Vector CurrentVel = input.veloity;
        Vector AirInteract = zeroVector(); 
        //TODO: implement air friction WILL REQUIRE CHANGES ABOVE AND BELOW
        Vector NextAcc = vecSum(CurrentAcc, ScalarDiv(Force, input.mass));
        Vector NextPos = vecSum(vecSum(CurrentPos, scalarMult(CurrentVel, params.dt)), scalarMult(CurrentAcc, pow(params.dt,2)/2)); //verbose for xcur + vcur*dt + acur*dt^2/2
        Vector NextVel = ScalarDiv(vecSum(CurrentAcc, NextAcc),2);        
        input.position = NextPos;
        input.acceleration = NextAcc;
        input.veloity = NextVel;
        //long out of bounds check
        if(NextPos.x > params.upperX || NextPos.x < params.lowerX || NextPos.y > params.upperY || NextPos.y<params.lowerY || NextPos.z > params.upperZ || NextPos.z<params.lowerZ) {
            input.enabled = 0;
        }
    }
    return input;
}

