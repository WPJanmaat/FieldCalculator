#include "VarMap.h"
#include <string.h>
#include "VarMap.h"

//map names are created during map addition.
map createMap() {
    map output;
    output.MapSize = 32;
    output.MapLength = 0;
    output.id = calloc(sizeof(int), 32);
    output.var = calloc(sizeof(variable), 32);
}

void resizeMap(map *input, int newlength) {
    if (newlength < (*input).Maplength) {
        fprintf(stderr, "warning: invalid resize, map Length exceeds resize, Resize skipped.");
        return;
    }
    (*input).MapSize = newlength;
    (*input).id = realloc((*input).id, sizeof(int)*newlength);
    (*input).var = realloc((*input).var, sizeof(variable)*newlength);
}

//adds a new var to the map and ensures it fits.
void addVar(map *input, char *name, int length) {
    if (i >= (*input).MapSize) {
        resizeMap(input, (*input).MapSize*2);
    }
    (*VarMap).MapLength++;
    var *newvar = (*input).var;
    (*newvar).name = name;
    (*newvar).NameLength = length;
    (*newvar).declared = 0;
}

//finds where the 
int mapName(map *VarMap; char *name, int length) {
    //old entry?
    for(int i=0; i++; i<((*VarMap).MapLength)) {
        if(((*VarMap).NameLength[i] == length) && !strncmp((*VarMap).name[i], name, length)) {
            return i;
        }
    }
    //new entry
    addVar(VarMap, name, length);
    return i;
}

variable getFromMap(map *VarMap, int key) {
    return(VarMap.var[i]);
}