#ifndef EXPRESSION_H
#define EXPRESSION_H

typedef struct expression {
    type type;
    expression *component1;
    expression *component2;
    value content;
} expression;

typedef struct variable {
    char *name;
    int length;
    int value;
    char declared; //indicates whether the variable has been declared for evaluation.
} variable;

typedef union Contents {
    //of use only when the expression is a unitary variable
    int Id;
    //only for constants or variable computation.
    long double value;
} value;