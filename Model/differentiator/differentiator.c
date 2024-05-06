#include <cstdio>
#include <cstdlib>
#include <stdlib>
#include <stdio.h>
#include <cstddef>
#include "./Expression.h"
#include "./VarMap.h"
#include "./Types.h"
#include "../Control/expressionParser.h"


expression *differentiatePlus(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiatePlus");
        EXIT_FAILURE;
    }
    return plus(differentiateExpression(diffID, (*input).component1, VarMap), 
                differentiateExpression(diffID, (*input).component2, VarMap));
}

expression *differentiateMinus(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateMinus");
        EXIT_FAILURE;
    }
    return minus(differentiateExpression(diffID, (*input).component1, VarMap), 
                differentiateExpression(diffID, (*input).component2, VarMap));
}

expression *differentiateMult(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateMult");
        EXIT_FAILURE;
    }
    return plus(
            mult(differentiateExpression(diffID, (*input).component1, VarMap), (*input).component2), 
                mult(differentiateExpression(diffID, (*input).component2, VarMap), (*input).component1));
}

expression *differentiateDiv(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateMult");
        EXIT_FAILURE;
    }
    expression *denominator;
    //I trust the pow() function to be intelligent.
    denominator = powF((*input).component2, createNum(2));
    //the numerator is long and convoluted in this notation, so it is split.
    expression *numerator;
    expression *nterm1, nterm2;
    nterm1 = mult(differntiateExpression(diffID, (*input).component1, VarMap), (*input).component2);
    nterm1 = mult(differntiateExpression(diffID, (*input).component2, VarMap), (*input).component1);
    numerator = minus(nterm1, nterm2);
    return div(numerator, denominator);
}

//d/dx f(x)^g(x) = (g(x)/f(x)+ln(f(x))*(d/dx g(x)))*f(x)^g(x)
expression *differentaitePow(int diffID, expression *input map VarMap) { 
    //g(x)/f(x)
    expression *frac1 = div((*input).component2, (*input).component1);
    //ln(f(x))
    expression *term1 = logF((*input).component1);
    //d/dx g(x)
    expression *diff1 = differentiateExpression((*input).component2);
    //ln(f(X))*d/dx g(x)
    expression *term2 = mult(term1, diff1);
    expression *mult1 = plus(frac1, term2);
    return mult(mult1, input);
}


//this returns a *new* expression, which is the old expression differentiated along the indicated variable.
expression *differentiateExpression (int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateExpression");
        EXIT_FAILURE;
    }
    switch((*input).type) {
        case Plus:
            return differentiatePlus(diffID, input, VarMap);
            break;

        case Minus:
            return differentiateMinus(diffID, input, VarMap);
            break;

        case Mult:
            return differentiateMult(diffID, input, VarMap);
            break;

        case Div:
            return differentiateDiv(diffID, input, VarMap);
            break;

        case Pow:
            return differentiatePow(diffID, input, VarMap);
            break;

        case Sin:
            return differentiateSin(diffID, input, VarMap);
            break;

        case Cos:
            return differentiateCos(diffID, input, VarMap);
            break;

        case Tan:
            return differentiateTan(diffID, input, VarMap);
            break;

        case Log:
            return differentiateLog(diffID, input, VarMap);
            break;

        case Variable:
            return differentiateVar(diffID, input, VarMap);
            break;

        case Number:
            return differentiateNum(diffID, input, VarMap);
            break;
    }
}
