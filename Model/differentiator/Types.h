
//TODO: The factured memory is inefficient, this could be transformed into RPN
//alternatively an implementation-heavy array form of trees.
typedef struct expression {
    type type;
    expression *component1;
    expression *component2;
    value content;
} expression;

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

typedef union Contents {
    //of use only when the expression is a unitary variable
    Key Id;
    //only for constants or variable computation.
    long double value;
} value;