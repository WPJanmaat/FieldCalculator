#include "./../../headers/Model/Results.h"

ResultNode createResult(double time, Particle* PList, int length) {
    ResultNode output;
    output.time = time;
    output.ParticleList = calloc(sizeof(Particle), length);
    if (output.ParticleList == NULL) {
        printf("ResultParticles is NULL\n");
    }
    if (PList == NULL) {
        printf("PList is NULL\n");
    }
    //Create copy rather than reference, as results are time snapshots.
    for(int i = 0; i<length; i++) {
        Particle copy = PList[i];
        output.ParticleList[i] = copy;
    }
    return output;
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
    output.length =0;
    output.size = expectedSize;
    return output;
}

void addResult(Resultset* resultset, ResultNode newResult) {
    if(resultset->length >= (resultset->size)-1) {
        resizeResults(resultset, resultset->size + 1000);
    }
    (*resultset).results[resultset->length] = newResult;
    resultset->length+=1;
    
}

void freeResult(Resultset input) {

}