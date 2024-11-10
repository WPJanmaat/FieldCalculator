#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Particle.h"
#include "FieldModulate.h"
#include "Field.h"
#include "Results.h"

Resultset Simulate(ParticleList ParticleList, Field* ACField, Field* DCField, Parameters params, int report);

#endif