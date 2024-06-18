#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Particle.h"
#include "FieldModulate.h"
#include "Field.h"

void Simulate(Particle* ParticleList, Field* ACField, Field* DCField, int length, Parameters params, int report);

#endif