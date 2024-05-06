#include "Expression.h"
#ifndef TYPES_H
#define TYPES_H

//TODO: The factured memory is inefficient, this could be transformed into RPN
//alternatively an implementation-heavy array form of trees.


//expand as implemented.
typedef enum Types{
    Number,
    Variable,
    Mult,
    Plus,
    Minus,
    Div,
    Pow, //root folded into Pow
    Sin,
    Cos,
    Tan,
    Log //log e
} type;

expression *plus(expression *a, expression *b);
expression *minus(expression *a, expression *b);
expression *mult(expression *a, expression *b);
expression *div(expression *a, expression *b);
expression *powF(expression *a, expression *b);
expression *sinF(expression *a);
expression *cosF(expression *a);
expression *tanF(expression *a);
expression *logF(expression *a);

#endif