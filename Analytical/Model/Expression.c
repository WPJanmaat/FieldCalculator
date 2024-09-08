#include <stdio.h>
#include <stdlib.h>
#include "Types.h"
#include "Expression.h"
#include "VarMap.h"

double evaluateExpression(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateExpression\n");
        exit(EXIT_FAILURE);
    }
    switch((*input).type){
        case Plus:
            return evaluatePlus(input, VarMap);
            break;

        case Minus:
            return evaluateMinus(input, VarMap);
            break;

        case Mult:
            return evaluateMult(input, VarMap);
            break;

        case Div:
            return evaluateDiv(input, VarMap);
            break;

        case Pow:
            return evaluatePow(input, VarMap);
            break;

        case Sin:
            return evaluateSin(input, VarMap);
            break;

        case Cos:
            return evaluateCos(input, VarMap);
            break;

        case Tan:
            return evaluateTan(input, VarMap);
            break;

        case Log:
            return evaluateLog(input, VarMap);
            break;

        case Variable:
            return evaluateVar(input, VarMap);
            break;

        case Number:
            return evaluateNum(input, VarMap);
            break;
    }
}


double evaluatePlus(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluatePlus\n");
        exit(EXIT_FAILURE);
    }
    return evaluateExpression(input->component1, VarMap) + evaluateExpression((input->component2), VarMap);
}

double evaluateMinus(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateMinus\n");
        exit(EXIT_FAILURE);
    }
    return evaluateExpression(input->component1, VarMap) - evaluateExpression(input->component2, VarMap);
}

double evaluateMult(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateMult\n");
        exit(EXIT_FAILURE);
    }
    return evaluateExpression(input->component1, VarMap) * evaluateExpression((input->component2), VarMap);
}

double evaluateDiv(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateDiv\n");
        exit(EXIT_FAILURE);
    }
    return evaluateExpression(input->component1, VarMap) / evaluateExpression((input->component2), VarMap);
}

double evaluatePow(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluatePows\n");
        exit(EXIT_FAILURE);
    }
    return pow(evaluateExpression(input->component1, VarMap), evaluateExpression((input->component2), VarMap));
}

double evaluateSin(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateSin\n");
        exit(EXIT_FAILURE);
    }
    return sin(evaluateExpression(input->component1, VarMap));
}

double evaluateCos(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateCos\n");
        exit(EXIT_FAILURE);
    }
    return cos(evaluateExpression(input->component1, VarMap));
}

double evaluateTan(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateTan\n");
        exit(EXIT_FAILURE);
    }
    return tan(evaluateExpression(input->component1, VarMap));
}

double evaluateLog(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateLog\n");
        exit(EXIT_FAILURE);
    }
    return cos(evaluateExpression((input->component1), VarMap));
}

double evaluateVar(expression *input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateCos\n");
        exit(EXIT_FAILURE);
    }
    variable var = getFromMap(VarMap, (input->content.Id));
    //TODO: Find good undeclared response.
    if(var.declared == 0) {
        printf("Warning: Value considered undeclared.\n");
    }
    return var.value;
}

double evaluateNum(expression *input, map Varmap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateNum\n");
        exit(EXIT_FAILURE);
    }
    return input->content.value;
}

//creates a new expression. if there is no content (i.e. not a var or a number) any value can be entered.
expression *createExpr(type type, expression* firstcomp, expression* secondcomp, value content) {
    expression *output = calloc(sizeof(expression), 1);
    if (type == Number || type == Variable) {
        (*output).content = content;
    }
    (*output).component1 = firstcomp;
    (*output).component2 = secondcomp;
    (*output).type = type;
    return output;
}

//create a new number (a shorthand for createExpr)
expression *createNum(double input) {
    value content;
    content.value = input;
    return createExpr(Number, NULL, NULL, content);
}

/*creates a completely separate copy of the input expression, 
 * for maintaining memory safety (e.g. in differentiation) and avoid intermingling for free() safety*/
expression *copy(expression *input) {
	if(input == NULL) return NULL;
	return createExpr((*input).type, copy(input->component1), copy(input->component2), (*input).content);
}
