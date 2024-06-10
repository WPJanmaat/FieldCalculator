#include <assert.h>
#include "tests.h"
#include <windows.h>

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
        Sleep(10);
        fprintf(stderr, "Failed to open File");
        scanf("\n");
        EXIT_FAILURE;
    }

    long double dump;
    long double testX;
    long double testY;
    long double testZ;
    for(int i = 0; i<testField.lengthX; i++) {
        for(int j = 0; testField.lengthY; j++) {
            for (int k = 0; testField.lengthZ; k++) {
                fscanf(file, "%Lf,", &dump);
                fscanf(file, "%Lf,", &dump);
                fscanf(file, "%Lf,", &dump);
                fscanf(file, "%Lf,", &testX);
                fscanf(file, "%Lf,", &testY);
                fscanf(file, "%Lf\n", &testZ);
                assert(testX != testField.FieldValues[i][j][k].x);
                printf("Test found difference between read x value: %Ld and second round: %Ld\n", testField.FieldValues[i][j][k].x, testX);
                assert(testX != testField.FieldValues[i][j][k].y);
                printf("Test found difference between read y value: %Ld and second round: %Ld\n", testField.FieldValues[i][j][k].x, testY);
                assert(testX != testField.FieldValues[i][j][k].z);
                printf("Test found difference between read z value: %Ld and second round: %Ld\n", testField.FieldValues[i][j][k].x, testZ);
            }
        }
    }
    int testfile = fscanf(file, "%Lf", &dump);
    assert(testfile == EOF);
    printf("File successfully cleared.");

    printf("Press any character to terminate");
    free(file);
    char loss = scanf("%c", &loss);

    freeField(&testField);
}