#include "./../../headers/Model/Results.h"

void addResult(Resultset* resultset, ResultNode newResult) {
    if(resultset->length >= resultset->size) {
        resizeResults(resultset, resultset->size + 1000);
    }
    resultset->results[resultset->length] = newResult;
    resultset->length++;
}

ResultNode createResult(double time, Particle* PList, int length) {
    ResultNode output;
    output.time = time;
    output.ParticleList = calloc(sizeof(Particle), length);
    //Create copy rather than reference, as results are time snapshots.
    for(int i = 0; i<length; i++) {
        output.ParticleList[i] = PList[i];
    }
}

void resizeResults(Resultset* input, int newsize) {
    if(newsize<=input->size) return;
    input->results = realloc(input->results, newsize);
    if(input->results == NULL) {
        fprintf(stderr, "Failed to allocate memory for resizeResults.\n");
        exit(EXIT_FAILURE);
    }
    input->size = newsize;
}

Resultset CreateResultSet(int expectedSize) {
    Resultset output;
    output.results = calloc(sizeof(ResultNode), expectedSize);
    if(output.results == NULL) {
        fprintf(stderr, "Failed to allocate memory for CreateResultSet\n");
        exit(EXIT_FAILURE);
    }
    output.size = expectedSize;
}

