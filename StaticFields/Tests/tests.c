#include <assert.h>
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void CSVTest() {
    FieldProperties props;
    props.XStart = -3.0000;
    props.Xend = 3.0000;
    props.Xstep = 0.1000;

    props.YStart = -3.0000;
    props.Yend = 3.0000;
    props.Ystep = 0.1000;

    props.ZStart = -3.0000;
    props.Zend = 3.0000;
    props.Zstep = 0.1000;

    Field testField = ParseField("./../Tests/testFiles/TestField.csv", props);

    FILE* file = fopen("./../Tests/testFiles/TestField.csv", "r");

    if(file == NULL) {
        fprintf(stderr, "Failed to open File\n");
        scanf("\n");
        exit(EXIT_FAILURE);
    }

    double dump1, dump2, dump3;
    double testX;
    double testY;
    double testZ;
    for(int k = 0; k<testField.lengthX; k++) {
        for(int j = 0; j<testField.lengthY; j++) {
            for (int i = 0; i<testField.lengthZ; i++) {
                if(feof(file)) {
                    printf("Failed to completee read at x: %d, y:%d z:%d\n", i,j,k);
                    break;
                }
                fscanf(file, "%lf,%lf,%lf,%lf,%lf,%lf\n", &dump1, &dump2, &dump3, &testX, &testY, &testZ); // read X position
                assert(testX == testField.FieldValues[i][j][k].x);
                assert(testY == testField.FieldValues[i][j][k].y);
                assert(testZ == testField.FieldValues[i][j][k].z);
            }
        }
    }
    assert(feof(file));
    printf("File successfully cleared.\n");

    printf("ParseTest complete, press enter to continue\n");
    fclose(file);
    scanf("\n");

    freeField(&testField);
}

//compares the particle path results to a given file for the first particle in the simulation.
void compareResults(Resultset testresults, char* filepath) {
    FILE* file = fopen(filepath, "r");

    if(file == NULL) {
        fprintf(stderr, "Failed to open File\n");
        scanf("\n");
        exit(EXIT_FAILURE);
    }

    Vector filePos;

    for(int i = 0; i < testresults.length; i++) {
        fscanf(file, "%lf\n", &filePos.x);
        fscanf(file, "%lf\n", &filePos.y);
        fscanf(file, "%lf\n", &filePos.z);
        printf("Timestep %d", i);
        printf("sim result: ");
        printVector(testresults.results[i].ParticleList[0].position);
        printf("file result: ");
        printVector(filePos);
    }
}

void SimTest() {
    Parameters simparams;
    simparams.ACV = 600;
    simparams.DCV = 5;
    simparams.endTime = 0.000400;
    simparams.freq = 19767.98;
    simparams.lowerX = simparams.lowerY = simparams.lowerZ = -2.9;
    simparams.upperX = simparams.upperY = simparams.upperZ = 2.9;
    simparams.dt = 0.00000001;
    simparams.startTime = 0;
    simparams.pressure = 0;
    simparams.scale = 0.001;
    Vector position = zeroVector();
    position.x = 1;
    position.y = 0.5;
    //z = 0
    //lookup params
    int singleton = 1;
    Particle type = createParticle(0.0000005, -0.0000000000001, 0);
    Particle* Plist = ParticleRelease(&(type), &singleton, singleton, 0, list, &position, NULL);


    FieldProperties props;
    props.XStart = -3.0000;
    props.Xend = 3.0000;
    props.Xstep = 0.1000;

    props.YStart = -3.0000;
    props.Yend = 3.0000;
    props.Ystep = 0.1000;

    props.ZStart = -3.0000;
    props.Zend = 3.0000;
    props.Zstep = 0.1000;

    Field ACField = ParseField("./../Tests/testFiles/AC...", props);
    Field DCField = ParseField("./../Tests/testFiles/DC...", props);

    Resultset testresults = Simulate(Plist, &ACField, &DCField, 1, simparams, 100);
    compareResults(testresults, "./../Tests/testFiles/...."); //from 0 to 400 microsec per 1 microsec
}