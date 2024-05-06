#ifndef VARMAP_H
#define VARMAP_H

#include "Expression.h"

typedef struct varmap {
    int MapSize;
    int MapLength;
    int *id;
    variable *var;
} map;

map createMap();
void resizeMap(map *input, int newlength);
void addVar(map *input, char *name, int length);
int mapName(map *VarMap, char *name, int length);
variable getFromMap(map VarMap, int key);

#endif