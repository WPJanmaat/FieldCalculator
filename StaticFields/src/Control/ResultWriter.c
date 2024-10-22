#include "../../headers/Control/ResultWriter.h"

void WriteResults(Resultset results) {
    FILE *f = fopen("../Results/Results.csv", "w");
    fprintf(f, "time,");
    for(int i =0; i<results.results[0].particleList.length; i++) {
        fprintf(f, "x%d,y%d,z%d,",i,i,i);
    }
    fprintf(f, "\n");
    for (int i=0; i< results.length; i++) {
        fprintf(f, "%lf,", results.results[i].time);
        for(int j=0; j < results.results[i].particleList.length; j++) {
            Particle current = results.results[i].particleList.List[j];
            Vector CurrentPos = getParPos(current);
            fprintf(f, "%lf,%lf,%lf,", CurrentPos.x, CurrentPos.y, CurrentPos.z);
        }
        fprintf(f,"\n");
    }
}