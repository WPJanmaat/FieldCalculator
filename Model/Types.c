#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "Expression.h"

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
expression *pow(expression *a, expression *b) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Pow;
    (*output).component1 = a;
    (*output).component2 = b;
    return output; 
}

//sin(a)
expression *sin(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = Sin;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}

//cos(a)
expression *cos(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = cos;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}

//tan(a)
expression *tan(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = tan;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}

//log(a) (ln(a))
expression *log(expression *a) {
    expression *output = calloc(sizeof(expression), 1);
    (*output).type = log;
    (*output).component1 = a;
    (*output).component2 = NULL;
    return output; 
}