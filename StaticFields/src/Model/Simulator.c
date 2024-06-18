#include "../../headers/Model/simulator.h"

Resultset Simulate(Particle* ParticleList, Field* ACField, Field* DCField, int length, Parameters params, int report) {
    int i=0;
    int j=0;

    //+1 due to truncation
    int expectedResults = (int) (((params.endTime-params.startTime)/params.dt)/report)+1;
    Resultset output = CreateResultSet(expectedResults);

    //strange loop, interrupts every report runs to eliminate disabled Particles and give output
    while(i*params.dt+params.startTime < params.endTime) {
        for(i; i < report*j; i++){
            simulateStep(ParticleList, ACField, DCField, length, i, params);
        }
        ResultNode newResult = createResult(i*params.dt+params.startTime, ParticleList, length);
        addResult(&output, newResult);
        length = eliminateParticles(ParticleList, length);
        j++;
    }
    return output;
}

void simulateStep(Particle *particleList, Field* ACField, Field* DCField, int length, int timestep, Parameters params){
    Vector *forceList = calloc(sizeof(Vector), length);
    for (int i=0; i++; i<length) {
        Vector NextForce = ModulateField(ACField, DCField, getParPos(particleList[i]), timestep, params);
        //n^/2 :) best I can do short of creating field analysis.
        for (int j=i+1; j++; j<length) {
            Vector Pforce = getForce(particleList[i], particleList[j]);
            forceList[i] = vecSum(forceList[i], Pforce);
            forceList[j] = vecSum(forceList[j], invertVec(Pforce)); //action is minus reaction, force on the second particle can already be calculated.
        }
        //TODO: implement magnetic interactions?
        NextForce = vecSum(NextForce, forceList[i]);
        updateParticle(particleList[i], NextForce, params);
    }
}

/**Helper function implementing leapfrog on a single timestep (t to t+1)
 * @param input: the particle subject to leapfrog;
 * @param Force: the force the particle is subjected to;
 * @param params: the parameters for the simulations;
*/
Particle updateParticle(Particle input, Vector force, Parameters params) {
    if(input.enabled) {
        //leapfrog implementation
        Vector CurrentPos = input.position;
        Vector CurrentAcc = input.acceleration;
        Vector CurrentVel = input.velocity;
        Vector AirInteract = zeroVector(); // air friction gives 0 for now
        //TODO: implement air friction WILL REQUIRE CHANGES ABOVE AND BELOW
        Vector NextAcc = vecSum(CurrentAcc, scalarDiv(force, input.mass));
        Vector NextPos = vecSum(vecSum(CurrentPos, scalarMult(CurrentVel, params.dt)), scalarMult(CurrentAcc, pow(params.dt,2)/2)); //verbose for xcur + vcur*dt + acur*dt^2/2
        Vector NextVel = scalarDiv(vecSum(CurrentAcc, NextAcc),2);        
        input.position = NextPos;
        input.acceleration = NextAcc;
        input.velocity = NextVel;
        //long out of bounds check
        if(NextPos.x > params.upperX || NextPos.x < params.lowerX || NextPos.y > params.upperY || NextPos.y<params.lowerY || NextPos.z > params.upperZ || NextPos.z<params.lowerZ) {
            input.enabled = 0;
        }
    }
    return input;
}

