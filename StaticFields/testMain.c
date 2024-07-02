#include <windows.h>
#include "./Tests/tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
    fprintf(stderr, "initialising tests\n");
	CSVTest();
    SimTest();
    return 0;
}