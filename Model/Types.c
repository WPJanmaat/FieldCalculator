#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "Expression.h"
#include <cstddef>

//a + b
expression *plus(expression *a, expression *b) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Plus;
    (*output).component1 = a;
    (*output).component2 = b;
    return output; 
}

//a - b
expression *minus(expression *a, expression *b) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Minus;
    (*output).component1 = a;
    (*output).component2 = b;
    return output; 
}

// a * b
expression *mult(expression *a, expression *b) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Mult;
    (*output).component1 = a;
    (*output).component2 = b;
    return output; 
}

// a / b
expression *div(expression *a, expression *b) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Div;
    (*output).component1 = a;
    (*output).component2 = b;
    return output; 
}

// a ^ b
expression *powF(expression *a, expression *b) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Pow;
    (*output).component1 = a;
    (*output).component2 = b;
    return output; 
}

//sin(a)
expression *sinF(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Sin;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}

//cos(a)
expression *cosF(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Cos;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}

//tan(a)
expression *tanF(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Tan;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}

//log(a) (ln(a))
expression *logF(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Log;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}