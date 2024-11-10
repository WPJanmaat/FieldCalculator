#include <stdio.h>
#include <stdlib.h>
#include "./Expression.h"
#include "./VarMap.h"
#include "./Types.h"
#include "../Control/expressionParser.h"

//TODO: Make sure all pointers returned are new and unique to ensure memory safety for free() operations.

expression *differentiatePlus(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiatePlus \n");
        exit(EXIT_FAILURE);
    }
    return plus(differentiateExpression(diffID, (*input).component1, VarMap), 
                differentiateExpression(diffID, (*input).component2, VarMap));
}

expression *differentiateMinus(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateMinus \n");
        exit(EXIT_FAILURE);
    }
    return minus(differentiateExpression(diffID, (*input).component1, VarMap), 
                differentiateExpression(diffID, (*input).component2, VarMap));
}

expression *differentiateMult(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateMult \n");
        exit(EXIT_FAILURE);
    }
    return plus(
            mult(differentiateExpression(diffID, (*input).component1, VarMap), copy((*input).component2)), 
                mult(differentiateExpression(diffID, (*input).component2, VarMap), copy((*input).component1)));
}

expression *differentiateDiv(int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateDiv \n");
        exit(EXIT_FAILURE);
    }
    expression *denominator;
    //I trust the pow() function to be intelligent.
    denominator = powF(copy((*input).component2), createNum(2));
    //the numerator is long and convoluted in this notation, so it is split.
    expression *numerator;
    expression *nterm1, nterm2;
    nterm1 = mult(differntiateExpression(diffID, (*input).component1, VarMap), copy((*input).component2));
    nterm1 = mult(differntiateExpression(diffID, (*input).component2, VarMap), copy((*input).component1));
    numerator = minus(nterm1, nterm2);
    return divide(numerator, denominator);
}

//d/dx f(x)^g(x) = (g(x)/f(x)+ln(f(x))*(d/dx g(x)))*f(x)^g(x)
expression *differentiatePow(int diffID, expression *input, map VarMap) { 
	if(input == NULL) {
        fprintf(stderr, "NULL input on differentiatePow \n");
        exit(EXIT_FAILURE);
    }
    //g(x)/f(x)
    expression *frac1 = divide(copy((*input).component2), copy((*input).component1));
    //ln(f(x))
    expression *term1 = logF(copy((*input).component1));
    //d/dx g(x)
    expression *diff1 = differentiateExpression(diffID, copy((*input).component2), VarMap);
    //ln(f(X))*d/dx g(x)
    expression *term2 = mult(term1, diff1);
    expression *mult1 = plus(frac1, term2);
    return mult(mult1, input);
}

expression *differentiateSin(int diffID, expression *input, map VarMap) { 
	if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateSin\n");
        exit(EXIT_FAILURE);
    }
    return mult(differentiateExpression(diffID, (*input).component1, VarMap), cosF(copy((*input).component1)));
}

expression *differentiateCos(int diffID, expression *input, map VarMap) { 
	if(input == NULL) {
		fprintf(stderr, "NULL input on differentiateCos\n");
		exit(EXIT_FAILURE);
	}
	expression *prod = mult(differentiateExpression(diffID, (*input).component1, VarMap), createNum(-1));
	return mult(prod, sinF(copy((*input).component1)));
}

expression *differentiateTan(int diffID, expression *input, map VarMap) { 
	if(input == NULL) {
		fprintf(stderr, "NULL input on differentiateTan\n");
		exit(EXIT_FAILURE);
	}
	expression *numerator = differentiateExpression(diffID, input->component1, VarMap);
	expression *denominator = powF(cosF(copy(input->component1)), createNum(2));
	return divide(numerator, denominator);
}

expression *differentiateLog(int diffID, expression *input, map VarMap) { 
	if(input == NULL) {
		fprintf(stderr, "NULL input on differentiateLog\n");
		exit(EXIT_FAILURE);
	}
	return divide(createNum(1), copy((*input).component1));
}

expression *differentiateNum(int diffID, expression *input, map VarMap) { 
	return createNum(0);
}

expression *differentiateVar(int diffID, expression *input, map VarMap) { 
	if ((*input).content.Id == diffID) {
		return createNum(1);
	}
	return createNum(0);
}

//this returns a *new* expression, which is the old expression differentiated along the indicated variable.
expression *differentiateExpression (int diffID, expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateExpression\n");
        exit(EXIT_FAILURE);
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
