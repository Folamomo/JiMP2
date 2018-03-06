//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorialit(int value);

int factorialrec(int value);

bool CheckOutOfRange(int value);

int Factorial(int value) {
    if (CheckOutOfRange(value)) {
        return 0;
    }
    //return factorialit(value);
    return factorialrec(value);
}

bool CheckOutOfRange(int value) { return value >= 13 || value <= -13; }

int factorialit(int value) {
    int result = 1;

    for(;value!=0;value-=(value > 0) ? 1 : -1)
        result*=value;
    return result;
}

int factorialrec(int value) {
    if (value == 0){
        return 1;
    } else {
        return value * factorialrec(value > 0 ? (value-1) : (value+1));
    }
}