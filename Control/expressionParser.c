#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "./model/Types.h"
#include "./model/Expression.h"
/*It is assumed for this program that the input expression is a valid one, a checker could be implemented later if necessary*/

char *getinput(){
    while((char read = getchar()) != "\n" && read != EOF){
        
    }
}

//factor is either (expression), a number, or a variable 
expression *ParseFactor(char *input, input length) {
    expression *output = NULL;
    for(int i=0; i<length; i++) {
        if(input[i] == '(') {
            int j=i+1;
            while(j<length && input[j] != ')') {
                j++;
            }
            output = ParsePlus(input+i+1, j-i);
            j+=(j<lenght && j==')');
            break;
        }

        if(isalphanumeric(input[i])){
            type item = Number;
            int j = i;
            while (isalphanumeric(input[j]) && j<length) {
                if (isalpha(input[j])) item = Variable;
                j++;
            }
            expression *output = calloc(sizeof(exrpession), 1);
            (*output).type = item;
            if(int == Variable) {
                (*output).content.Id = mapVar(input[i], j-i);
            } else {
                (*output).content.value = getValue(input[i], j-i);
            }
            break;          
        }
    }
    if(j<length){
        printf("Warning: dropped unparsed section: ");
        while(j<length){
            printf("%c", input[j]);
        }
    }
    if (output == NULL){
        fprintf(stderr, "Invalid expression; empty expression or empty parantheses?");
        EXIT_FAILURE;
    }
    return(output);
}

//TODO: The factured memory is inefficient see Types.h TODO
expression *ParsePlus(token *input, int length){
    expression *output = calloc(sizeof(expression), 1);
    if (input[0] == '+' || input[0] == '-') {
        (*output).type = input[0]== '+' ? Plus : Minus;
        (*output)->component1 = ParsePlus("0");
        (*output)->component2 = ParsePlus((input+1), length-1);
        return(output);
    }
    //skip parts in paranthesis for submitted for higher order evaluation, eventually they will be surrounded by operators.
    for (int i=1; i<length; i++) {
        if (input[i] == '(') {
            int j=i+1;
            while(input[j] != ')' && j < length) {
                j++;
            }
            //skip
            i=j+1;
        }
        if(input[i] == '+' || input[i] == '-') {
            (*output).type = input[i]== '+' ? Plus : Minus;
            (*output)->component1 = ParsePlus(input, i-1);
            (*output)->component2 = ParsePlus((input+i+1), length-i);
            return(output);
        }
    }
    //an equation devoid of additions.
    free(output);
    return(ParseMult(input, length));
}

expression *ParseMult(token* input, int length) {
    expression *output = calloc(sizeof(expression), 1);

    if (input[0] == '/' || input[0] == '*') {
        fprintf(stderr, "invalid input");
        EXIT_FAILURE;
    }
    
    //skip parts in paranthesis for submitted for higher order evaluation, eventually they will be surrounded by operators.
    for (int i=1; i<length; i++) {
        if (input[i] == '(') {
            int j=i+1;
            while(input[j] != ')' && j < length) {
                j++;
            }
            //skip
            i=j+1;
        }
        if(input[i] == '*' || input[i] == '/') {
            (*output).type = input[i]== '*' ? Mult : Div;
            (*output)->component1 = ParseMult(input, i-1);
            (*output)->component2 = ParseMult((input+i+1), length-i);
            return(output);
        }
    }
    //an equation devoid of multiplications.
    free(output);
    return(ParsePow(input, length));
}

//TODO: Figure out how to generalise algorithmic differentiation for e^x vs x^n
expression *ParsePow(token* input, int length) {
    expression *output = calloc(sizeof(expression), 1);
    if (input[0] == '^') {
        fprintf(stderr, "invalid input");
        EXIT_FAILURE;
    }
    //skip parts in paranthesis for submitted for higher order evaluation, eventually they will be surrounded by operators.
    for (int i=1; i<length; i++) {
        if (input[i] == '(') {
            int j=i+1;
            while(j<length && input[j] != ')') {
                j++;
            }
            //skip
            i=j+1;
            //someone forgot the closing bracket.
            if(j>=length) break;
        }
        if(input[i] == '^') {
            (*output).type = Pow;
            (*output)->component1 = ParsePow(input, i-1);
            (*output)->component2 = ParsePow((input+i+1), length-i);
            return(output);
        }
    }
    //an equation devoid of Powers.
    free(output);
    return(ParseFunctions(input, length));
}

//To be used for parsing functions with a one-sided input (e.g. sin(f(x)) rather than f(x)+g(y))
expression ParseFunctions(char *input, int length) {
    expression *output = calloc(sizeof(expression), 1);
    for (int i=0; i<length; i++) {

        //skip parantheses.    
        if (input[i] == '(') {
            int j=i+1;
            while(j<length && input[j] != ')') {
                j++;
            }
            //skip
            i=j+1;
            //someone forgot the closing bracket.
            if(j>=length) break;
        }

        //sin
        if(input[i] == s && length-i>=4) {
            if(!strncmp("sin(", input[i], 4)) {
                (*output).type = sin;
                int j=i+4;
                while(j<length && input[j] != ')') {
                    j++;
                }
                (*output)->component1 = ParsePlus((input+i+4), j-(i+4));
                (*output)->component2 = NULL;
            }
        }
        
        //cos
        if(input[i] == c && length-i>=4) {
            if(!strncmp("cos(", input[i], 4)) {
                (*output).type = cos;
                int j=i+4;
                while(input[j] != ')') {
                    j++;
                    if (j>=length) break;
                }
                (*output)->component1 = ParsePlus((input+i+4), j-(i+4));
                (*output)->component2 = NULL;
            }
        }
        
        //tan
        if(input[i] == t && length-i>=4) {
            if(!strncmp("tan(", input[i], 4)) {
                (*output).type = tan;
                int j=i+4;
                while(input[j] != ')') {
                    j++;
                    if (j>=length) break;
                }
                (*output)->component1 = ParsePlus((input+i+4), j-(i+4));
                (*output)->component2 = NULL;
            }
        }

        //log
        if(input[i] == l && length-i >=3) {
            if((!strncmp("log(", input[i], 4)) || (!strncmp("ln(", input[i], 3))) {
                (*output).type = log;
                int j=i+3;
                while(input[j] != ')' && j < length) {
                    j++;
                }
                       
            }
            (*output)->component1 = (!strncmp("log(", input[i], 4)) ? ParsePlus((input+i+4), j-(i+4)) : ParsePlus((input+i+3), j-(i+3)); //different steplength for log vs ln
            (*output)->component2 = NULL;
        }
    }
    //an equation devoid of pre-defined functions.
    return(ParseParentheses(input, length));
}
/* number finder
    for(int i = 0; i<length; i++) {
        char read = input[i];
        char *numarr = calloc(sizeof(char), 16);
        int numlength = 16;
        int readnumlen = 0;
        while((read <= 57 && read >= 48) || read == '.') { //any number or a decimal dot
            readnumlen++;
            if (readnumlen >= numlength) {
                realloc(numarr, 2*numlength*sizeof(char));
                numlength*=2;
            }
        }
    } 
*/