//A helper header for containing the field properties on parsing
#ifndef FIELDPROPERTIES_H
#define FIELDPROPERTIES_H

typedef struct FieldProperties {
    double XStart;
    double Xend;
    double Xstep;
    
    double YStart;
    double Yend;
    double Ystep;

    double ZStart;
    double Zend;
    double Zstep;
} FieldProperties;

#endif