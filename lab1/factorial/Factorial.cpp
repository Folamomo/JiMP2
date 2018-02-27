//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
    if (value>=13||value<=-13)
        return 0;

    int result = 1;

    for(;value!=0;value-=(value > 0) ? 1 : -1)
        result*=value;
    return result;
}

