#ifndef FIELDPARSER_H
#define FIELDPARSER_H
#include "../Model/Field.h"
#include "FieldProperties.h"
#include "../Model/Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Field ParseField(char *filepath, FieldProperties properties);

#endif