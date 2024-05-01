#ifndef VARMAP_H
#define VARMAP_H


#include "Expression.h"

typedef struct varmap {
    int MapSize;
    int MapLengt;
    int *id;
    variable *var;
} map;