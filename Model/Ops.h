#include "Expression.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef OPS_H
#define OPS_H

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