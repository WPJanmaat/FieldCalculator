#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Particle.h"
#include "FieldModulate.h"
#include "Field.h"
#include "Results.h"

Results Simulate(Particle* ParticleList, Field* ACField, Field* DCField, int length, Parameters params, int report);

#endif