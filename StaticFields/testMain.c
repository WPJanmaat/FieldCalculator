#include "./Tests/tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    printf("initialising tests\n");
	CSVTest();
    printf("starting Simtest\n");
    SimTest();
    return 0;
}