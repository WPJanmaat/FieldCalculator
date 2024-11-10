#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "Types.h"

typedef union Contents {
    //of use only when the expression is a unitary variable
    int Id;
    //only for constants or variable computation.
    double value;
} value;

typedef struct expression {
    type type;
    struct expression *component1;
    struct expression *component2;
    value content;
} expression;

typedef struct variable {
    char *name;
    int length;
    double value;
    char declared; //indicates whether the variable has been declared for evaluation.
} variable;



expression *createNum(double value);
#endif