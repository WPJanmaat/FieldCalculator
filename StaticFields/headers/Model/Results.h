#ifndef RESULTS_H
#define RESULTS_H
#include "Particle.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct ResultNode {
    double time;
    ParticleList particleList;
} ResultNode;

typedef ResultNode* Results;

typedef struct Resultset {
    int size; //total available space
    int length; //filled space
    Results results;
} Resultset;

void addResult(Resultset* resultset, ResultNode newResult);
ResultNode createResult(double time, ParticleList PList);
Resultset CreateResultSet(int expectedSize);

#endif