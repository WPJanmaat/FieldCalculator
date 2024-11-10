#ifndef FIELDPARSER_H
#define FIELDPARSER_H
#include "../Model/Field.h"
#include "FieldProperties.h"
#include "../Model/Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Parses the E fields.
 * @param char* filepath: the filepath to a CSV of field values, @param FieldProperties properties: The given properties of the field (size, value density etc).
*/
Field ParseField(char *filepath, FieldProperties properties);

#endif