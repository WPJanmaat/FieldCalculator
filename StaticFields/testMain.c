#include "./Tests/tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    printf("initialising tests\n");
	CSVTest();
    ParticleTest();
    printf("starting Simtest\n");
    SimTest();
    AccuracyTest();
    return 0;
}