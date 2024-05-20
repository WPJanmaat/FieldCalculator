#ifndef FIELD_H
#define FIELD_H
//A simple 3D Field construction
typedef struct Field {
    //number of entries
    int lengthX;
    int lengthY;
    int lengthZ;

    long double steplengthX;
    long double *Xvals;
    
    long double steplengthY;
    long double *Yvals;
    
    long double steplengthZ;
    long double *Zvals;
} Field;

#endif