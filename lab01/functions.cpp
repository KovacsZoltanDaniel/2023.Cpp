//
// Created by Dani on 2023. 09. 27..
//

#include "functions.h"
#include <cmath>

int countBits(int number) {
    int count = 0;
    while (number > 0){
        if(number & 1){
            count++;
        }
        number >>= 1;
    }
    return count;
}

bool setBit(int &number, int order) {
    if (order < 0 || order > 31) {
        return false; // Érvénytelen sorszám
    }

    int mask = 1 << order; // Sorszámhoz tartozó maszk létrehozása
    number |= mask; // Bit beállítása 1-re a logikai "vagy" művelettel
    return true;
}

double mean(double *array, int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double average = 0;
    for (int i = 0; i < numElements; ++i) {
        average += array[i];
    }
    return average / numElements;
}

