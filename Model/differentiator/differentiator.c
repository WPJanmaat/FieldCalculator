expression *differentiatePlus(int diffID, expresion input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiatePlus");
        EXIT_FAILURE;
    }
    return plus(differentiateExpression(*(input.component1), VarMap), 
                differentiateExpression(*(input.component2), VarMap));
}

expression *differentiateMinus(int diffID, expresion input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateMinus");
        EXIT_FAILURE;
    }
    return minus(differentiateExpression(*(input.component1), VarMap), 
                differentiateExpression(*(input.component2), VarMap));
}

expression *differentiateMult(int diffID, expresion input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateMult");
        EXIT_FAILURE;
    }
    return plus(
            mult(differentiateExpression(*(input.component1), VarMap), *(input.component2)), 
                mult(differentiateExpression(*(input.component2), VarMap), *(input.component1)));
}

expression *differentiateExpression (int diffID, expression input, map VarMap) {
    if(input == NULL) {
        fprintf(stderr, "NULL input on differentiateExpression");
        EXIT_FAILURE;
    }
    switch((*input.type):
        case Plus:
            return differentiatePlus(diffID input, VarMap);
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

        case sin:
            return differentiateSin(diffID, input, VarMap);
            break;

        case cos:
            return differentiateCos(diffID, input, VarMap);
            break;

        case tan:
            return differentiateTan(diffID, input, VarMap);
            break;

        case log:
            return differentiateLog(diffID, input, VarMap);
            break;

        case Variable:
            return differentiateVar(diffID, input, VarMap);
            break;

        case Number:
            return differentiateNum(diffID, input, Varmap);
            break;
}
