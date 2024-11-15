#include "./../../headers/Model/Results.h"

ResultNode createResult(double time, ParticleList PList) {
    ResultNode output;
    output.time = time;
    output.particleList.List = calloc(sizeof(Particle), PList.length);
    if (output.particleList.List == NULL) {
        printf("ResultParticles is NULL\n");
    }
    if (PList.List == NULL) {
        printf("PList is NULL\n");
    }
    //Create copy rather than reference, as results are time snapshots.
    for(int i = 0; i<PList.length; i++) {
        output.particleList.List[i] = PList.List[i];
    }
    output.particleList.length=PList.length;
    return output;
}

void resizeResults(Resultset* input, int newsize) {
    if(newsize<=input->size) return;
    input->results = realloc(input->results, newsize*sizeof(ResultNode));
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
    free(input.results);
}

//get the final position of the indicated particle
Vector getFinalPos(Resultset input, int index) {
    ResultNode finalResult = input.results[input.length-1];
    if (finalResult.particleList.length <= index) {
        fprintf(stderr, "getFinalPosition, index out of scope: %d", index);
        return zeroVector();
    }
    int finalIndex = finalResult.particleList.length-1;
    Particle FinalParticle = finalResult.particleList.List[finalIndex];
    return getParPos(FinalParticle);
}