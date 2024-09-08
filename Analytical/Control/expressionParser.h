#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "./Model/Types.h"
#include "./Model/Expression.h"

expression ParseFunctions(char *input, int length);
expression *ParseFactor(char *input, int length);