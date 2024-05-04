#include "Types.h"
#include "Expression.h"
#include <string.h>
#include "VarMap.h"

long double evaluatePlus(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluatePlus");
        EXIT_FAILURE;
    }
    return evaluateExpression(*(input->component1), VarMap) + evaluateExpression(*(input->component2), VarMap);
}

long double evaluateMinus(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateMinus");
        EXIT_FAILURE;
    }
    return evaluateExpression(*(input->component1), VarMap) - evaluateExpression(*(input->component2), VarMap);
}

long double evaluateMult(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateMult");
        EXIT_FAILURE;
    }
    return evaluateExpression(*(input->component1), VarMap) * evaluateExpression(*(input->component2), VarMap);
}

long double evaluateDiv(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateDiv");
        EXIT_FAILURE;
    }
    return evaluateExpression(*(input->component1), VarMap) / evaluateExpression(*(input->component2), VarMap);
}

long double evaluatePow(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluatePows");
        EXIT_FAILURE;
    }
    return pow(evaluateExpression(*(input->component1), VarMap), evaluateExpression(*(input->component2), VarMap));
}

long double evaluateSin(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateSin");
        EXIT_FAILURE;
    }
    return sin(evaluateExpression(*(input->component1), VarMap));
}

long double evaluateCos(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateCos");
        EXIT_FAILURE;
    }
    return cos(evaluateExpression(*(input->component1), VarMap));
}

long double evaluateTan(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateTan");
        EXIT_FAILURE;
    }
    return tan(evaluateExpression(*(input->component1), VarMap));
}

long double evaluateLog(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateLog");
        EXIT_FAILURE;
    }
    return cos(evaluateExpression(*(input->component1), VarMap));
}

long double evaluateVar(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateCos");
        EXIT_FAILURE;
    }
    var = getFromMap(Expression.content.id);
    //TODO: Find good undeclared response.
    if(var.declared == 0) {
        printf("Warning: Value considered undeclared.\n");
    }
    return var.value;
}

long double evaluateNum(expression input, map Varmap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateNum");
        EXIT_FAILURE;
    }
    return expression.content.value;
}

long double evaluateExpression(expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on evaluateExpression");
        EXIT_FAILURE;
    }
    switch((*input.type):
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

        case sin:
            return evaluateSin(input, VarMap);
            break;

        case cos:
            return evaluateCos(input, VarMap);
            break;

        case tan:
            return evaluateTan(input, VarMap);
            break;

        case log:
            return evaluateLog(input, VarMap);
            break;

        case Variable:
            return evaluateVar(input, VarMap);
            break;

        case Number:
            return evaluateNum(input, Varmap);
            break;
}