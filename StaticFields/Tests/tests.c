#include <assert.h>
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        printf("pain");
        fprintf(stderr, "Failed to open File");
        scanf("\n");
        exit(EXIT_FAILURE);
    }

    double dump;
    double testX;
    double testY;
    double testZ;
    for(int i = 0; i<testField.lengthX; i++) {
        for(int j = 0; testField.lengthY; j++) {
            for (int k = 0; testField.lengthZ; k++) {
                fscanf(file, "%lf,", &dump);
                fscanf(file, "%lf,", &dump);
                fscanf(file, "%lf,", &dump);
                fscanf(file, "%lf,", &testX);
                fscanf(file, "%lf,", &testY);
                fscanf(file, "%lf\n", &testZ);
                assert(testX != testField.FieldValues[i][j][k].x);
                printf("Test found difference between read x value: %lf and second round: %lf\n", testField.FieldValues[i][j][k].x, testX);
                assert(testX != testField.FieldValues[i][j][k].y);
                printf("Test found difference between read y value: %lf and second round: %lf\n", testField.FieldValues[i][j][k].x, testY);
                assert(testX != testField.FieldValues[i][j][k].z);
                printf("Test found difference between read z value: %lf and second round: %lf\n", testField.FieldValues[i][j][k].x, testZ);
            }
        }
    }
    int testfile = fscanf(file, "%lf", &dump);
    assert(testfile == EOF);
    printf("File successfully cleared.");

    printf("Press any character to terminate");
    fclose(file);
    char loss = scanf("%c", &loss);

    freeField(&testField);
}