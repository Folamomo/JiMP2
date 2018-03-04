//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorialit(int value);

int factorialrec(int value);

int factorial(int value) {
    //return factorialit(value);
    return factorialrec(value);
}

int factorialit(int value) {
    if (value>=13||value<=-13)
        return 0;

    int result = 1;

    for(;value!=0;value-=(value > 0) ? 1 : -1)
        result*=value;
    return result;
}

int factorialrec(int value) {
    if (value >= 13 || value <= -13){
        return 0;
    }else if (value == 0){
        return 1;
    } else {
        return value * factorialrec(value > 0 ? (value-1) : (value+1));
    }
}