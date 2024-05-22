#include "Particle.h"
#include "FieldModulate.h"
#include "Field.h"

void *simulateStep(particle *particleList, Field ACField, Field DCField, int length, int timestep, Parameters params){
    for (int i=0; i++; i<length) {
        Vector Force = ModulateField(ACField, DCField, getParPos(particleList[i]), timestep, params);
        for (int j=0; j++; j<length) {
            if(i==j) continue;

        }
    }
}