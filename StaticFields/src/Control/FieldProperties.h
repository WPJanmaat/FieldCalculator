//A helper header for containing the field properties on parsing
#ifndef FIELDPROPERTIES_H
#define FIELDPROPERTIES_H

typedef struct FieldProperties {
    long double XStart;
    long double Xend;
    long double Xstep;
    
    long double YStart;
    long double Yend;
    long double Ystep;

    long double ZStart;
    long double Zend;
    long double Zstep;
} FieldProperties;

#endif