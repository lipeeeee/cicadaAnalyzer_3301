#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cicada/cicada.h"
#include "main.h"

void analyzeString(char* str) {

}

void analyzeNumber(int num) {
    printf("isPrime(): %d", isPrime(&num));
}

void analyzeValue(char* value) {
    int valueIsDigit = strIsDigit(value);

    if (valueIsDigit == 1) {
        analyzeNumber(atoi(value));
    } else {
        analyzeString(value);
    }
}