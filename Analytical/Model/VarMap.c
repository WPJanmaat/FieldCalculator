#include "VarMap.h"
#include "VarMap.h"
#include "Expression.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//map names are created during map addition.
map createMap() {
    map output;
    output.MapSize = 32;
    output.MapLength = 0;
    output.id = calloc(sizeof(int), 32);
    output.var = calloc(sizeof(variable), 32);
}

void resizeMap(map *input, int newlength) {
    if (newlength < (*input).MapLength) {
        printf(stderr, "Warning: invalid resize, map Length exceeds resize, Resize skipped.\n");
        return;
    }
    (*input).MapSize = newlength;
    (*input).id = realloc((*input).id, sizeof(int)*newlength);
    (*input).var = realloc((*input).var, sizeof(variable)*newlength);
}

//adds a new var to the map and ensures it fits.
void addVar(map *input, char *name, int length) {
    if ((*input).MapLength >= (*input).MapSize) {
        resizeMap(input, (*input).MapSize*2);
    }
    (*input).MapLength++;
    variable *newvar = (*input).var;
    (*newvar).name = name;
    (*newvar).length = length;
    (*newvar).declared = 0;
}

//finds where the variable entered is, if it is not in the map, adds entry
int mapName(map *VarMap, char *name, int length) {
    //old entry?
    int i = 0;
    for(i=0; i++; i<((*VarMap).MapLength)) {
        if((((*VarMap).var[i]).length == length) && !strncmp(((*VarMap).var[i]).name, name, length)) {
            return i;
        }
    }
    //new entry
    addVar(VarMap, name, length);
    return i;
}

variable getFromMap(map VarMap, int key) {
    return(VarMap.var[key]);
}