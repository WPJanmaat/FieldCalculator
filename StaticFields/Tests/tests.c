#include <assert.h>
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
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
                if(testX != testField.FieldValues[i][j][k].x) {
                    printf("Test found difference between read x value: %lf and second parse: %lf\n", testField.FieldValues[i][j][k].x, testX);
                    printf("position x: %d, y: %d, z: %d\n", i,j,k);
                    Sleep(5);
                }
                if(testY != testField.FieldValues[i][j][k].y) {
                    printf("Test found difference between read y value: %lf and second parse: %lf\n", testField.FieldValues[i][j][k].y, testY);
                    Sleep(5);
                }
                if(testZ != testField.FieldValues[i][j][k].z) { 
                    printf("Test found difference between read z value: %lf and second parse: %lf\n", testField.FieldValues[i][j][k].z, testZ);
                    Sleep(5);
                }
            }
        }
    }
    assert(feof(file));
    printf("File successfully cleared.\n");

    printf("Press any character to terminate\n");
    fclose(file);
    char loss = scanf("%c", &loss);

    freeField(&testField);
}