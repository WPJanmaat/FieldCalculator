#ifndef TYPES_H
#define TYPES_H


//TODO: The factured memory is inefficient, this could be transformed into RPN
//alternatively an implementation-heavy array form of trees.


//expand as implemented.
typedef enum Types{
    Number;
    Variable;
    Mult;
    Plus;
    Minus;
    Div;
    Pow; //root folded into Pow
    sin;
    cos;
    tan;
    log; //log e
} type;

